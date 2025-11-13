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
    vector<vector<int>> adj(n + 1);
    vector<int> ind(n + 1, 0);
    for(int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      ind[v] += 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (ind[i] == 0) {  
        q.push(i);
      }
    }
    vector<int> ans;
    while (q.size() > 0) {
      int u = q.front();
      q.pop();
      ans.push_back(u);
      for (auto v : adj[u]) {
        if (--ind[v] == 0) {
          q.push(v);
        }
      }
    }
    if ((int)ans.size() == n) {
      for (auto x : ans) {
        cout << x << ' ';
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}