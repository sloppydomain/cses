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
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto bfs = [&](int s, int w) {
      queue<int> q;
      q.push(s);
      vector<int> d(n + 1, -1);
      d[s] = 0;
      while (q.size() > 0) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (d[v] == -1) {
            d[v] = d[u] + 1;
            q.push(v); 
          }
        }
      }
      int mx = -1;
      int e = -1;
      for (int i = 1; i <= n; i++) {
        if (d[i] > mx) {
          mx = d[i];
          e = i;
        }
      }
      return (w == 0 ? e : mx);
    };
    int e = bfs(1, 0);
    cout << bfs(e, 1);
  }
  return 0;
}