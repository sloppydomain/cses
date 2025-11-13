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
        vector<pair<int, char>> a;
        for (int i = 0; i < n; i++) {
            int x, y;   
            cin >> x >> y;
            a.push_back({x, 'L'});
            a.push_back({y, 'R'});
        }
        sort(a.begin(), a.end());
        int cnt = 0, ans = -1;
        for (int i = 0; i < 2 * n; i++) {
            if (a[i].second == 'L') {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}
