#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> f;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]] += 1;
  }
  const int mod = 1e9 + 7;
  int ans = 1;
  for (auto& p : f) {
    ans = (1LL * ans * (p.second + 1)) % mod;
  }
  ans = (ans - 1 + mod) % mod; // empty subsequence
  cout << ans << '\n';
  return 0;
}