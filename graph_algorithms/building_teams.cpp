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
        vector<int> ans(n + 1, -1);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == -1) {
                queue<int> q;
                q.push(i);
                ans[i] = 0;
                while (q.size() > 0) {
                    int from = q.front();
                    q.pop();
                    for (auto to : g[from]) {
                        if (ans[to] == -1) {
                            ans[to] = ans[from] ^ 1;
                            q.push(to);
                        } else if (ans[to] == ans[from]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) break;
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE";
        } else {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] + 1 << " \n"[i == n];
            }
        }
    }
    return 0;
}
