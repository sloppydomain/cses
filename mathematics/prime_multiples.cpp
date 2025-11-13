#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 1; i < (1 << k); i++) {
            long long p = 1;
            int bits = 0;
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) {
                    if (p > n / a[j]) {
                        p = n + 1;
                        break;
                    }
                    p *= a[j];  
                    bits += 1;
                }
            }
            ans += ((bits & 1) ? n / p : -n / p); 
        }
        cout << ans << '\n';
    }
    return 0;
}