#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0)); // dp[i][j] = max pages I can buy considering first i books with cost j
    for (int i = 1; i <= n; i++) {
      for (int c = 1; c <= x; c++) {
        dp[i][c] = dp[i - 1][c];
        if (c >= h[i - 1]) {
          dp[i][c] = max(dp[i][c], dp[i - 1][c - h[i - 1]] + s[i - 1]);
        }
      }
    }
    int ans = -1;
    for (int c = 1; c <= x; c++) {
      ans = max(ans, dp[n][c]);
    }
    cout << ans << '\n';
  }
  return 0;
}