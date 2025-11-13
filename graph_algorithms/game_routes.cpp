#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v] += 1;
  }
  const int inf = 1e9 + 7;
  queue<int> q;
  for (int v = 1; v <= n; v++) {
    if (in[v] == 0) {
      q.push(v);
    }
  }
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  while (q.size() > 0) {
    int fro = q.front();
    q.pop();
    for (int to : g[fro]) {
      in[to] -= 1;
      if (in[to] == 0) {
        q.push(to);
      }
      dp[to] = (dp[to] + dp[fro]) % inf;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}