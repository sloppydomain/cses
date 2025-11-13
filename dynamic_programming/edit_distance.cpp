#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n, m;
    n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0) {
          dp[i][j] = j;
        } else if (j == 0) {
          dp[i][j] = i;
        } else if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (s[i - 1] != t[j - 1]) {
          dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
      }
    }
    cout << dp[n][m] << '\n';
  }
  return 0;
}
