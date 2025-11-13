#include <bits/stdc++.h>
using namespace std;
 
void dfs(string curr, string s, vector<bool> v, set<string>& ans) {
    int n = s.length(), m = curr.length();
    if (n == m) {
        ans.insert(curr);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!v[j]) {
            curr.push_back(s[j]);
            v[j] = true;
            dfs(curr, s, v, ans);
            curr.pop_back();
            v[j] = false;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        set<string> ans;
        vector<bool> v(s.length(), false);
        dfs("", s, v, ans);
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x << '\n';
        }
    }
    return 0;
}
