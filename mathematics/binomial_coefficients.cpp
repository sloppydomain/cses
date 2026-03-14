#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int mod = 1e9 + 7, mx = 1e6;
  auto be = [&](long long a, long b) {
    long long ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };  
  vector<long long> fact(mx + 1);
  fact[0] = 1;
  for (int i = 1; i <= mx; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  vector<long long> invfact(mx + 1);
  invfact[mx] = be(fact[mx], mod - 2);
  for (int i = mx - 1; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1) % mod;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cout << fact[a] * invfact[b] % mod * invfact[a - b] % mod << '\n';
  }
  return 0;
}