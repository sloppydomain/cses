#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, m, q;
    cin >> n >> m >> q;
    const long long inf = 1e18;
    vector<vector<long long>> g(n + 1, vector<long long>(n + 1, inf));
    for (int i = 1; i <= n; i++) {
      g[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      long long u, v, c;
      cin >> u >> v >> c;
      g[u][v] = min(g[u][v], c);
      g[v][u] = min(g[v][u], c);
    }
    for (int k = 1; k <= n; k++) {
      for (int u = 1; u <= n; u++) {
        for (int v = 1;v <= n; v++) {
          if (g[u][k] != inf && g[k][v] != inf) {
            g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
          }
        }
      }
    }
    while (q--) {
      int u, v;
      cin >> u >> v;
      cout << (g[u][v] == inf ? -1 : g[u][v]) << '\n';
    }
  }
  return 0;
}
