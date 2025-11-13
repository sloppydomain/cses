#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long low = *max_element(a.begin(), a.end()), high = accumulate(a.begin(), a.end(), 0LL);
  while (low < high) {
    long long mid = low + (high - low) / 2, cur = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (cur + a[i] > mid) {
        cur = 0, cnt++;
      }
      cur += a[i];
    }
    if (cnt <= k - 1) {
      high = mid;
    } else {
      low = mid + 1;
    }
  } 
  cout << high << '\n';
  return 0;
}