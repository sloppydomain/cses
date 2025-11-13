#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> cnt(n);
  cnt[0] = 1;
  long long pref = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pref += x;
    int r = ((pref % n) + n) % n;
    ans += cnt[r];
    ++cnt[r];
  } 
  cout << ans << '\n';
  return 0;
}
