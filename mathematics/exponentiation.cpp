#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t a, b;
    cin >> a >> b;
    const int mod = 1e9 + 7;
    auto be = [&](int64_t base, int64_t exp) {
      int64_t ans = 1;
      while (exp > 0) {
        if (exp & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp >>= 1; // e / 2
      }
      return ans;
    };
    cout << be(a, b) << '\n';
  }
  return 0;
}