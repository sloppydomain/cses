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
        sort(a.begin(), a.end());
        long long curr = 0, ans = tot;
        for (int i = 0; i < n; i++) {
            ans = min(ans, tot - (curr + a[i]) - 1LL * (n - i - 1) * a[i] + 1LL * i * a[i] - curr);            
            curr += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}