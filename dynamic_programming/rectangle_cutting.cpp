#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    const int inf = 1e9;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, inf));
    for (int i = 1; i <= min(a, b); i++) {
      dp[i][i] = 0; // already squares
    }
    // dp[i][j] = min moves to convert i * j into squares
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        if (i == j) {
          continue;
        }
        for (int v = 1; v < j; v++) {
          dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j - v] + 1);
        }
        for (int h = 1; h < i; h++) {
          dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
        }
      }
    }
    cout << dp[a][b] << '\n';
  }
  return 0;
}