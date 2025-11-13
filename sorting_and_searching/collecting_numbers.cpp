#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            --x;
            b[x] = i;
        }
        int ci = -1, ans;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ci = b[i];
                ans = 1;
            } else if (b[i] > ci) {
                ci = b[i];
            } else if (b[i] < ci) {
                ci = b[i];
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}