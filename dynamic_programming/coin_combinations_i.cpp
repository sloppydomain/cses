#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e9 + 7;

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> dp(x + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(v[j] <= i){
                dp[i] = (dp[i] + dp[i - v[j]]) % N;
            }
        }
    }
    cout << dp[x] << "\n";
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
