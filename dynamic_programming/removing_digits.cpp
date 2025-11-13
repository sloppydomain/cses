#include <bits/stdc++.h>
using namespace std;
 
int dfs(int n, vector<int>& dp) {
  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];
  int m = n;
  int ans = 1e6;
  while (m > 0) {
    int d = m % 10;
    if (d != 0) {
      ans = min(ans, 1 + dfs(n - d, dp));
    }
    m /= 10;
  } 
  return dp[n] = ans;
}
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e6);
    dp[0] = 0; // dp[i] -> minimum steps to reach i from 0 or 0 from i
    for (int i = 1; i <= n; i++) {
      int m = i;
      while (m > 0) {
        int d = m % 10;
        if (d != 0) {
          dp[i] = min(dp[i], dp[i - d] + 1);
        }
        m /= 10;
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}