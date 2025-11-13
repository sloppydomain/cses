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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> mp;
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (mp[a[j]] == 0) {
                mp[a[j]] += 1;
                j += 1;
            } else {
                ans = max(ans, j - i);
                mp[a[i]] -= 1;
                i += 1;
            }
        }
        ans = max(ans, j - i);
        cout << ans << '\n';
    }
    return 0;
}
