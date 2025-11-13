#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      cin >> a[i][0], a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    for (int i = 0; i < n - 2; i++) {
      int r = t - a[i][0];
      for (int j = i + 1, k = n - 1; j < k && j < n - 1; j++) {
        while (j < k && a[j][0] + a[k][0] > r) {
          k -= 1;
        }
        if (j < k && a[j][0] + a[k][0] == r) {
          cout << a[i][1] << ' ' << a[j][1] << ' ' << a[k][1];
          return 0;
        }
      }
    }
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}