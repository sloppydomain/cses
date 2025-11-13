#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >>    tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        char dir[4] = {'U', 'D', 'L', 'R'};
        queue<pair<int, int>> q;
        vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));
        pair<int, int> e = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'A') {
                    q.push({i, j});
                    break;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (g[ni][nj] == 'B') {
                        e = {ni, nj};
                        p[ni][nj] = {i, j};
                        break;
                    }
                    if (g[ni][nj] == '.') {
                        g[ni][nj] = '#';
                        p[ni][nj] = {i, j};
                        q.push({ni, nj});
                    }
                }
            }
            if (e != make_pair(-1, -1)) break;
        }
        if (e != make_pair(-1, -1)) {
            cout << "YES\n";
            string pa = "";
            auto [i, j] = e;
            while (p[i][j] != make_pair(-1, -1)) {
                auto [ip, jp] = p[i][j];
                for (int k = 0; k < 4; k++) {
                    if (ip + di[k] == i && jp + dj[k] == j) {
                        pa += dir[k];
                    }
                }
                i = ip;
                j = jp;
            }
            reverse(pa.begin(), pa.end());
            cout << pa.length() << '\n' << pa << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}   