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
        vector<vector<int>> e(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        } 
        queue<int> q;
        vector<int> p(n + 1, -1);
        bool ok = false;
        int x = -1, y = -1;
        for (int v = 1; v <= n; v++) {
            if (p[v] == -1) {
                p[v] = -2;
                q.push(v);
                while (q.size() > 0) {
                    int from = q.front();
                    q.pop();
                    for (auto to : e[from]) {
                        if (p[to] != -1) {
                            if (p[from] != to) {
                                x = from;
                                y = to;
                                ok = true;
                                break;
                            }
                        } else {
                            p[to] = from;
                            q.push(to);
                        }
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE";
            continue;
        }
        vector<int> h1;
        for (int c = x; c != -2; c = p[c]) {
            h1.push_back(c);
        }
        vector<int> h2;
        for (int c = y; c != -2; c = p[c]) {
            h2.push_back(c);
        }
        reverse(h1.begin(), h1.end());
        reverse(h2.begin(), h2.end());
        int k = 0;
        while (k < h1.size() && k < h2.size() && h1[k] == h2[k]) {
            k += 1;
        }
        k -= 1;
        vector<int> ans;
        for (int i = k; i < h1.size(); i++) {
            ans.push_back(h1[i]);
        }
        for (int i = h2.size() - 1; i >= k; i--) {
            ans.push_back(h2[i]);
        }
        cout << ans.size() << '\n';
        for (auto a : ans) {
            cout << a << ' ';
        }
    }
    return 0;
}
