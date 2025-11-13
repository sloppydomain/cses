#include <bits/stdc++.h>
using namespace std;
 
long long dfs(int u, int p, vector<long long>& dp, vector<vector<int>>& e) {
  long long sub = 0;
  for (int v : e[u]) {
    if (v != p) {
      sub += 1 + dfs(v, u, dp, e);
    }
  }
  return dp[u] = sub;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int u;
    cin >> u;
    e[u].push_back(i + 1);
  }
  vector<long long> dp(n + 1);
  dfs(1, -1, dp, e);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " \n"[i == n];
  }
  return 0;
}