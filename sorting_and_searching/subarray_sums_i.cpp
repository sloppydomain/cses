#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    unordered_map<long long, long long> mp;
    mp[0] = 1;
    long long curr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      curr += a[i];
      mp[curr] += 1;
      ans += mp[curr - x];
    }
    cout << ans << '\n';
  }
  return 0;
}
