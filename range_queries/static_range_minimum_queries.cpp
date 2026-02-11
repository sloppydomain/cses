#include <bits/stdc++.h>
 
using namespace std;
 
struct seg_tree {
  int n;
  vector<long long> sum;
  vector<long long> mn;
  vector<long long> mx;
 
  seg_tree(const vector<long long>& a) {
    n = (int)a.size();
    sum.assign(4 * n, 0);
    mn.assign(4 * n, LLONG_MAX);
    mx.assign(4 * n, LLONG_MIN);
    build(0, 0, n - 1, a);
  }
 
  void build(int node, int l, int r, const vector<long long>& a) {
    if (l == r) {
      long long v = a[l];
      sum[node] = v;
      mn[node] = v;
      mx[node] = v;
      return;
    }
    int mid = (l + r) / 2;
    build(2 * node + 1, l, mid, a);
    build(2 * node + 2, mid + 1, r, a);
    sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
    mn[node] = min(mn[2 * node + 1], mn[2 * node + 2]);
    mx[node] = max(mx[2 * node + 1], mx[2 * node + 2]);
  }
 
  long long range_sum(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return sum[node];
    int mid = (l + r) / 2;
    long long left_sum = range_sum(2 * node + 1, l, mid, ql, qr);
    long long right_sum = range_sum(2 * node + 2, mid + 1, r, ql, qr);
    return left_sum + right_sum;
  }
 
  long long range_min(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return mn[node];
    int mid = (l + r) / 2;
    return min(range_min(2 * node + 1, l, mid, ql, qr), range_min(2 * node + 2, mid + 1, r, ql, qr));
  }
 
  long long range_max(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return LLONG_MIN;
    if (ql <= l && r <= qr) return mx[node];
    int mid = (l + r) / 2;
    return min(range_max(2 * node + 1, l, mid, ql, qr), range_max(2 * node + 2, mid + 1, r, ql, qr));
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    seg_tree st(a);
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << st.range_min(0, 0, n - 1, l, r) << '\n';
    }
  }
  return 0;
}