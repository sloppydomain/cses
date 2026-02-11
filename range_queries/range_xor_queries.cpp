#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
      b[i + 1] = b[i] ^ a[i];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << (b[r] ^ b[l]) << '\n';
    }
  }
  return 0;
}
