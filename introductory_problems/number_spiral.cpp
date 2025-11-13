#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        long long x, y, z, ans, v;
        cin >> x >> y;
        z = max(x, y);
        ans = 0;
        v = z * (z - 1) + 1;
        if (z & 1) {
            if (x <= y) {
                ans = v + (y - x);
            } else {
                ans = v - (x - y);
            }
        } else {
            if (x <= y) {
                ans = v - (y - x);
            } else {
                ans = v + (x - y);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}