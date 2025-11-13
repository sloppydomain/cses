#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tot += a[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(tot + 1, false)); // dp[i][j] = true for jth sum possible using elements till ith index
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
      for (int s = 1; s <= tot; s++) {
        dp[i][s] = dp[i - 1][s];
        if (s >= a[i - 1]) {
          dp[i][s] = (dp[i][s] || dp[i - 1][s - a[i - 1]]);
        }
      }
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
      for (int s = 1; s <= tot; s++) {
        if (dp[i][s]) {
          st.insert(s);
        }
      }
    }
    cout << st.size() << '\n';
    for (auto x : st) {
      cout << x << ' ';
    }
  }
  return 0;
}