#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007
void solve()
{
    ll n;
    cin >> n;
    ll count = 2;
    for (int i = 2; i <= n / 2; i++)
    {
        if (!(n % i))
            count++;
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
