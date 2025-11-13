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
        multiset<int> m;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m.insert(x);
        } // n * logn
        while (q--) {
            int price;
            cin >> price;
            auto it = m.lower_bound(price); // logn
            // auto it = lower_bound(m.begin(), m.end(), price); -> O(n)
            int ans = -1;
            if (!m.empty()) {
                if (it == m.end() || (*(it) > price && it != m.begin())) {
                    ans = *(--it);
                    m.erase(it); // logn
                } else if (*(it) == price) {
                    ans = price;
                    m.erase(it); // logn
                }
            }
            cout << ans << '\n';
        } // q * logn
    }
    return 0;
}

/*
tc : O((n + q) * logn)
sc : O(n)
*/