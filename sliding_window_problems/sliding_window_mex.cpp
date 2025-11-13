#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(i);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[x[i]] += 1;
      if (mp[x[i]] == 1) {
        s.erase(x[i]);
      }
      if (i >= k) {
        mp[x[i - k]] -= 1;
        if (mp[x[i - k]] == 0) {
          s.insert(x[i - k]);
        }
      }
      if (i >= k - 1) {
        cout << *s.begin() << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}