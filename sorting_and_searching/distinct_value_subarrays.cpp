#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  long long ans = 0;
  for (int r = 0, l = 0; r < n; r++) {
    mp[a[r]]++;
    while (mp[a[r]] == 2) {
      mp[a[l]]--;
      if (mp[a[l]] == 0) {
        mp.erase(a[l]);
      }
      l++;
    }
    ans += r - l + 1;
  }
  cout << ans << '\n';
  return 0;
}