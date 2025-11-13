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
    map<int, int> cnt;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      if (s.find({cnt[x[i]], -x[i]}) != s.end()) {
        s.erase({cnt[x[i]], -x[i]});
      }
      cnt[x[i]] += 1;
      s.insert({cnt[x[i]], -x[i]});
      if (i >= k) {
        s.erase({cnt[x[i - k]], -x[i - k]});
        cnt[x[i - k]] -= 1;
        if (cnt[x[i - k]] > 0) {
          s.insert({cnt[x[i - k]], -x[i - k]});
        }
      }
      if (i >= k - 1) cout << abs(s.rbegin()->second) << " \n"[i == n - 1];
    }
  }
  return 0;
}