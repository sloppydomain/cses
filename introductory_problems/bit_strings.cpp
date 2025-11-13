#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, ans = 0, i = 5;
    cin >> n;
    while (i <= n)
    {
        ans += n / i;
        i *= 5;
    }
    cout << ans << endl;
    return 0;
}
