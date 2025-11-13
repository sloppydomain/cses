#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const int inf = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (a[i] == 0) {
          for (int j = 1; j <= m; j++) {
            dp[i][j] = 1;
          }
        } else {
          dp[i][a[i]] = 1;
        }
      } else {
        if (a[i] == 0) {
          for (int j = 1; j <= m; j++) {
            for (int k = max(1, j - 1); k <= min(m, j + 1); k++) {
              dp[i][j] = (dp[i][j] +  dp[i - 1][k]) % inf;
            }
          }
        } else {
          for (int k = max(1, a[i] - 1); k <= min(m, a[i] + 1); k++) {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][k]) % inf;
          }
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      ans = (ans + dp[n - 1][i]) % inf;
    }
    cout <<  ans << '\n';
  }
  return 0;
}