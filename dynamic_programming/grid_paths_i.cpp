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
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    const int inf = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] != '*') {
          if (i == 0 && j == 0) {
            dp[i][j] = 1;
          } else if (i > 0 && j > 0) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % inf;
          } else if (i > 0) {
            dp[i][j] = dp[i - 1][j];
          } else if (j > 0) {
            dp[i][j] = dp[i][j - 1];
          }
        }
      }
    }
    cout << dp[n - 1][n - 1] << '\n';
  }
  return 0;
}
