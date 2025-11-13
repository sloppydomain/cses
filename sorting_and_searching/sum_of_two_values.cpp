#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int N = 200005;

void hello() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while(l < r) {
        int s = a[l].first + a[r].first;
        if(s == k) {
            cout << a[l].second + 1 << " " << a[r].second + 1 << "\n";
            return;
        }
        if(s > k) {
            r--;
        } else if(s < k) {
            l++;
        }
    }
    cout << "IMPOSSIBLE";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        hello();
    }
    return 0;
}
