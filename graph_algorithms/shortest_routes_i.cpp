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
        vector<vector<array<int, 2>>> g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        } 
        priority_queue<array<long long, 2>> pq;
        pq.push({0, 1});
        const long long INF = 1e18;
        vector<long long> d(n + 1, INF);
        d[1] = 0;
        while (pq.size()) {
            auto fro = pq.top();
            pq.pop();
            long long u = fro[1];
            if (-fro[0] > d[u]) {
                continue;
            }
            for (auto vw : g[u]) {
                long long v = vw[0], w = vw[1];
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    pq.push({-d[v], v});
                }
            }
        }
        for (int v = 1; v <= n; v++) {
            cout << d[v] << " \n"[v == n];
        }
    }
    return 0;
}