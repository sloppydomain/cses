#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tot += a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n)); 
    /* 
      dp[i][j] = max score a player can get in interval i to j
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    */
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (i == j) {
          dp[i][j] = a[i];
        } else {
          long long left_end = a[i] - dp[i + 1][j]; // if player one takes a[i] player 2 has to get maximum score in interval i + 1 to j
          long long right_end = a[j] - dp[i][j - 1]; // if player one takes a[j] player 2 has to get maximum score in interval i to j - 1
          dp[i][j] = max(left_end, right_end);
        }
      }
    }
    /*
      sum1 - sum2 = dp[0][n - 1]
      sum1 + sum2 = tot
      sum1 = (dp[0][n - 1] + tot) / 2
    */
    cout << (dp[0][n - 1] + tot) / 2;
  }
  return 0;
}