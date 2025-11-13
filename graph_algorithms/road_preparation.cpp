#include <bits/stdc++.h>
using namespace std;
 
class dsu {
public:
  vector<int> p, sz;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n, -1);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
 
  inline int get(int v) {
    if (v == p[v]) {
      return v;
    }
    return p[v] = get(p[v]);
  }
 
  inline void unite(int u, int v) {
    int rootu = get(u);
    int rootv = get(v);
    if (rootu != rootv) {
      if (sz[rootu] < sz[rootv]) {
        swap(rootu, rootv);
      }
      p[rootv] = rootu;
      sz[rootu] += sz[rootv];
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, pair<int, int>>> pq;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    pq.push({-w, {u, v}});
  }
  dsu d(n + 1);
  long long ans = 0;
  while (pq.size() > 0) {
    auto t = pq.top();
    pq.pop();
    int w = abs(t.first), u = t.second.first, v = t.second.second;
    if (d.get(u) != d.get(v)) {
      ans += w;
      d.unite(u, v);
    }
  }
  set<int> s;
  for (int v = 1; v <= n; v++) {
    s.insert(d.get(v));
  }
  if (s.size() == 1) {
    cout << ans;
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}
