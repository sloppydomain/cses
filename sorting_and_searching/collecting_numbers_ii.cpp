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
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[x] = i;
            b[i] = x;
        }
        int ans = 0, ci = -1;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                ci = a[i];
                ans = 1;
            } else if (a[i] > ci) {
                ci = a[i];
            } else if (a[i] < ci) {
                ci = a[i];
                ans += 1; 
            }
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            int e1 = b[x];
            int e2 = b[y];
            if (e1 == e2 + 1) {
                ans -= 1;
                if (a[e1 + 1] > x && a[e1 + 1] < y) ans += 1;
                if (a[e2 - 1] > x && a[e2 - 1] < y) ans += 1;
            } else if (e2 == e1 + 1) {
                ans += 1;
                if (a[e2 + 1] > x && a[e2 + 1] < y) ans -= 1;
                if (a[e1 - 1] > x && a[e1 - 1] < y) ans -= 1;
            } else {
                // e1
                if (a[e1 + 1] > x && a[e1 + 1] < y) ans += 1;
                if (a[e1 - 1] > x && a[e1 - 1] < y) ans -= 1;
 
                // e2
                if (a[e2 + 1] > x && a[e2 + 1] < y) ans -= 1;
                if (a[e2 - 1] > x && a[e2 - 1] < y) ans += 1;
            }
            b[y] = e1, b[x] = e2;
            a[e1] = y, a[e2] = x;
            cout << ans << '\n';
        }
    }
    return 0;
}