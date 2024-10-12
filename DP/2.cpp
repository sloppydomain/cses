#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> dp(x + 1, 1e9);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(v[j] <= i){
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
