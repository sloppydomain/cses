#include <bits/stdc++.h>
using namespace std;
 
class FenwickTree {
    public:
        vector<long long> fenw;
        int n;
 
        FenwickTree(int n_) : n(n_) {
            fenw.resize(n);
        }
        
        void modify(int i, int v) {
            while (i <= n) {
                fenw[i] += v;
                i += i & -i;
            }
        }
 
        long long query(int i) {
            long long sum = 0;
            while (i > 0) {
                sum += fenw[i];
                i -= i & -i;
            }
            return sum;
        }
};
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        FenwickTree ft(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ft.modify(i + 1, a[i]);
        }
        while (q--) {
            int c, x, y;
            cin >> c >> x >> y;
            if (c == 1) {
                ft.modify(x, y - a[x - 1]);
                a[x - 1] = y;
            } else {
                cout << ft.query(y) - ft.query(x - 1) << '\n';
            }
        }
    }
    return 0;
}