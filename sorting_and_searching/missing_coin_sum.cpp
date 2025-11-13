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
        sort(a.begin(), a.end());
        long long sum = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > sum) {
                break;
            } else {
                sum += a[i];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}