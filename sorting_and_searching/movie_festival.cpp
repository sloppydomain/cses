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
        vector<pair<int, int>> in(n);
        for (int i = 0; i < n; i++) {
            cin >> in[i].first >> in[i].second;
        }
        sort(in.begin(), in.end(), [&](auto& x, auto& y) {
            return (x.second < y.second);
        });
        int end = -1, ans = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                end = in[i].second;
            } else if (in[i].first >= end) {
                end = in[i].second;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}