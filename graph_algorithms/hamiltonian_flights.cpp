#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].push_back(b);
    }
    const int inf = 1e9 + 7;
    vector<vector<int64_t>> dp(1 << n, vector<int64_t>(n, 0));
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
        if (!(mask & (1 << u))) continue;
        if (dp[mask][u] == 0) continue;
        for (int v : g[u]) {
          if (mask & (1 << v)) continue;
          int nmask = mask | (1 << v);
          dp[nmask][v] = (dp[nmask][v] + dp[mask][u]) % inf;
        }
      }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
  }
  return 0;
}