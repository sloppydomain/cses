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
    int tot = n * (n + 1) / 2;
    if (tot & 1) {
      cout << 0;
    } else {
      const int inf = 1e9 + 7;
      int need = tot / 2;
      vector<vector<int>> dp(n + 1, vector<int>(need + 1, 0));
      dp[0][0] = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= need; j++) {
          dp[i][j] = dp[i - 1][j];
          if (i <= j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % inf;
          } 
        }
      }
      cout << (dp[n][need] * 1LL * (inf + 1) / 2) % inf;
    }
  }
  return 0;
}
