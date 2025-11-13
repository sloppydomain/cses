#include <bits/stdc++.h>
using namespace std;
 
int ans = 0;
bool safe(int r, int c, bool v[8][8]) {
    // column
    for (int i = 0; i < 8; i++) {
        if (v[i][c]) {
            return false;
        }
    }
    // right to left upper diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (v[i][j]) {
            return false;
        }
    }
    // left to right upper diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < 8; i--, j++) {
        if (v[i][j]) {
            return false;
        }
    }
    return true;
}
 
void get(int r, string ch[8], bool v[8][8]) {
    if (r == 8) {
        ans += 1;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (safe(r, c, v) && ch[r][c] != '*') {
            v[r][c] = true;
            get(r + 1, ch, v);
            v[r][c] = false;
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
        string ch[8];
        for (int i = 0; i < 8; i++) {
            cin >> ch[i];
        }
        bool v[8][8];
        memset(v, false, sizeof(v));
        get(0, ch, v);
        cout << ans << '\n';
    }
    return 0;
}
