#include <bits/stdc++.h>
using namespace std;
 
void dfs(int u, vector<vector<int>>& g, vector<bool>& vis) {
    for (auto v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, g, vis);
        }
    }
}
 
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
        vector<bool> vis(n + 1, false);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(i, g, vis);
                ans.push_back(i);
            }
        }
        int sz = ans.size();
        cout << sz - 1 << '\n';
        for (int i = 0; i < sz - 1; i++) {
            cout << ans[i] << ' ' << ans[i + 1] << '\n';
        }
    }
    return 0;
}
