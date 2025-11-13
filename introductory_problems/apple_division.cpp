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
        vector<int> a(n);
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        long long ans = n * 1e9;
        for (int i = 0; i < (1 << n); i++) {
            long long sum = 0;
            for (int j = 0; j < 20; j++) {
                if ((1 << j) & i) {
                    sum += a[j]; 
                }
            }
            ans = min(ans, abs(tot - 2 * sum));
        }
        cout << ans << '\n';
    }
    return 0;
}