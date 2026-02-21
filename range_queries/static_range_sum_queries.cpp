#include <bits/stdc++.h>

using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<long long> x(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> x[i + 1];
            x[i + 1] += x[i];
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << x[b] - x[a - 1] << '\n';
        }
    }
    return 0;
} 