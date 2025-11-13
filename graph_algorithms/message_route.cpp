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
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        vector<int> p(n + 1, -1), d(n + 1, 1);
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        while (q.size() > 0) {
            int from = q.front();
            q.pop();
            for (auto to : g[from]) {
                if (!vis[to]) {
                    vis[to] = true;
                    p[to] = from;
                    d[to] = d[from] + 1;
                    if (to == n) {
                        break;
                    }
                    q.push(to);
                }
            }
        }
        if (p[n] == -1) {
            cout << "IMPOSSIBLE";
        } else {
            cout << d[n] << '\n';
            vector<int> path;
            for (int c = n; c != -1; c = p[c]) {
                path.push_back(c);
            }
            reverse(path.begin(), path.end());
            for (auto x : path) {
                cout << x << ' ';
            }
        }
    }
    return 0;
}
