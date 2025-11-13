#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 42
#endif
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int x, n;
        cin >> x >> n;
        vector<int> a(n);
        set<int> s;
        s.insert(0);
        s.insert(x);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int mx = -1;
        for (auto i = s.begin(); next(i) != s.end(); i++) {
            mx = max(mx, *next(i) - *i);
        }
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(mx);
            auto p = s.find(a[i]);
            mx = max(mx, *next(p) - *prev(p));
            s.erase(p);
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans) {
            cout << x << ' ';
        }
    }
    return 0;
}
