#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    multiset<int> mx, mn;
    for (int i = 0; i < n; i++) {
      int s1 = mx.size(), s2 = mn.size();
      if (s1 == 0 && s2 == 0) {
        mn.insert(x[i]);
      } else {
        int v = *mn.rbegin();
        if (x[i] > v) {
          mx.insert(x[i]);
        } else {
          mn.insert(x[i]);
        }
      }
      if (mn.size() < mx.size()) {
        int v = *mx.begin();
        mn.insert(v);
        mx.erase(mx.find(v));
      } else if (mn.size() > mx.size() + 1) {
        int v = *mn.rbegin();
        mx.insert(v);
        mn.erase(mn.find(v));
      }
      if (i >= k) {
        if (mn.find(x[i - k]) != mn.end()) {
          mn.erase(mn.find(x[i - k]));
        } else {
          mx.erase(mx.find(x[i - k]));
        }
      }
      if (mn.size() < mx.size()) {
        int v = *mx.begin();
        mn.insert(v);
        mx.erase(mx.find(v));
      } else if (mn.size() > mx.size() + 1) {
        int v = *mn.rbegin();
        mx.insert(v);
        mn.erase(mn.find(v));
      }
      if (i >= k - 1) {
        cout << *mn.rbegin() << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}