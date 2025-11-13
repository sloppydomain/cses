#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> st;
  for (int i = 0; i < n; i++) {
    while (st.size() > 0 && a[st.back()] >= a[i]) {
      st.pop_back();
    }
    cout << (st.size() == 0 ? 0 : st.back() + 1) << " \n"[i == n - 1];
    st.push_back(i);
  } 
  return 0;
}
