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
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        auto it = s.begin();
        if (s.size() == 1) {
            cout << 1 << '\n';
            continue;
        } else {
            it++;
        }
        while (s.size() > 0) {
            cout << *it << ' ';
            it = s.erase(it);
            if (s.size() == 0) break;   
            if (it == s.end()) {
                it = s.begin();
            }
            it++;
            if (it == s.end()) {
                it = s.begin();
            }
        }
    }
    return 0;
}
