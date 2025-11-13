#include <bits/stdc++.h>
using namespace std;

vector<string> g(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> prev = g(n - 1);
    vector<string> next;
    int sz = prev.size();
    for (int i = 0; i < sz; i++) {
        string zero = "0" + prev[i];
        next.push_back(zero);
    }
    reverse(prev.begin(), prev.end());
    for (int i = 0; i < sz; i++) {
        string one = "1" + prev[i];
        next.push_back(one);
    }
    return next;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> ans = g(n);
        for (auto& s : ans) {
            cout << s << "\n";
        }
    }
    return 0;
}