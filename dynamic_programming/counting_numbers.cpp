#include <bits/stdc++.h>

using namespace std;

long long dp[20][11][2][2];
long long ask(string &s, int n, int p, int lz, int tight) {
  if (n == int(s.size())) return 1;
  int digs = 9;
  if (tight) {
    digs = s[n] - '0';
  }
  if (dp[n][p + 1][lz][tight] != -1) return dp[n][p + 1][lz][tight];
  long long ans = 0;
  for (int d = 0; d <= digs; d++) {
    if (!lz && d == p) continue;
    if (lz) {
      if (d == 0) {
        ans += ask(s, n + 1, -1, 1, 0);
      } else {
        ans += ask(s, n + 1, d, 0, tight && (d == digs));
      }
    } else {
      ans += ask(s, n + 1, d, 0, tight && (d == digs));
    }
  }
  return dp[n][p + 1][lz][tight] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b;
  cin >> a >> b;
  string x = to_string(a - 1);
  string y = to_string(b);
  memset(dp, -1, sizeof(dp));
  long long nb = ask(y, 0, -1, 1, 1);
  memset(dp, -1, sizeof(dp));
  long long na = ask(x, 0, -1, 1, 1);
  cout << nb - na;
  return 0;
}