#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        d[i] = x;
      } else {
        d[i] = (d[i - 1] * a + b) % c;
      }
    }
    long long s = 0, ans = 0;
    for (int r = 0; r <= n; r++) {
      if (r < k) {
        s += d[r];
      } else {
        ans = ans ^ s;
        s -= d[r - k];
        if (r < n) {
          s += d[r];
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}