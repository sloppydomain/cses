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
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (b.size() == 0) {
                b.push_back(a[i]);
            } else {
                int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
                if (p == b.size()) {
                    b.push_back(a[i]);
                } else {
                    b[p] = a[i];
                }
            }
        }
        cout << b.size() << '\n';
    }
    return 0;
}
