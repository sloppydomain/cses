#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int c, f;
    cin >> c >> f;
    vector<vector<pair<int, int>>> g(c + 1);
    for (int i = 0; i < f; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
    }     
    vector<vector<long long>> dp(c + 1, vector<long long>(2, LLONG_MAX)); // dp[i][0] = not applied operation anywhere along path 1 to i, dp[i][1] = have applied operation somewhere between node 1 and i
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    dp[1][0] = dp[1][1] = 0; // not needed since you cannot apply any operation before it as its the first node
    while (pq.size() > 0) {
      auto t = pq.top();
      pq.pop();
      long long w = abs(t.first);
      int u = t.second.first;
      int st = t.second.second;
      if (dp[u][st] < w) {
        continue;
      }
      for (auto v : g[u]) {
        int nu = v.first;
        long long nw = v.second;
        if (st == 0) {
          if (w + nw / 2 < dp[nu][1]) {
            dp[nu][1] = w + nw / 2;
            pq.push({-(w + nw / 2), {nu, 1}});
          }
        }
        if (w + nw < dp[nu][st]) {
          dp[nu][st] = w + nw;
          pq.push({-(w + nw), {nu, st}});
        }
      }
    }
    cout << min(dp[c][1], dp[c][0]);
  }
  return 0;
}