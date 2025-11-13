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
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> maybe(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        maybe[i] = x;
      } else {
        maybe[i] = (maybe[i - 1] * a + b) % c;
      }
    } 
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int mn = min({i + 1, k, n - i});
      if (mn % 2 == 1) {
        ans = ans ^ maybe[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
