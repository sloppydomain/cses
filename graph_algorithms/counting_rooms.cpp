#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        string s[h];
        for (int i = 0; i < h; i++) {
            cin >> s[i];
        }
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, 1, -1};
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            s[i][j] = '#';
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == '.') {
                    dfs(ni, nj);
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == '.') {
                    dfs(i, j);
                    ans += 1;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
tc: O(h * w)
sc: O(h * w)
*/