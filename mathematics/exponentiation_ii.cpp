#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    const int mod = 1e9 + 7;
    auto be = [](int b, int e, int mod) {
      int ans = 1;
      while (e) {
        if (e & 1) {
          ans = (1LL * ans * b) % mod;
        }
        b = (1LL * b * b) % mod;
        e >>= 1;
      }
      return ans;
    };
    cout << be(a, be(b, c, mod - 1), mod) << '\n';
  }
  return 0;
}