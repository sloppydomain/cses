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
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (a.size() == 0) {
                a.push_back(c);
            } else {
                int l = 0, r = a.size() - 1;
                while (l <= r) {
                    int m = (l + (r - l) / 2);
                    if (a[m] > c) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                if (r == a.size() - 1) {
                    a.push_back(c);
                } else {
                    a[r + 1] = c;
                }
            }
        }
        cout << a.size() << '\n';
    }
    return 0;
}