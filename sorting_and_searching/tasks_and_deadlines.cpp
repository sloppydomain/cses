#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  long long ans = 0, t = 0;
  for (int i = 0; i < n; i++) {
    t += p[i].first;
    ans += (p[i].second - t);
  }
  cout << ans;
  return 0;
}
