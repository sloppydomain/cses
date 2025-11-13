#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    long long n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long l = 1, r = 1e18;
    while (l <= r) {
      long long m = (l + (r - l) / 2);
      long long tot = 0;
      for (int i = 0; i < n; i++) {
        tot += m / a[i];
        if (tot >= t) {
          break;
        }
      }
      if (tot >= t) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << r + 1 << '\n';
  }
  return 0;
}