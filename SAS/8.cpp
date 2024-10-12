#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
    int n;
    cin >> n;
    ll ans = -1e18 , msf = -1e18;
    for(int i = 0; i<n; i++)
    {
        ll a;
        cin >> a;
        msf = max(a, a+msf);
        ans = max(msf,ans);
    }
    cout << ans << endl;
    return 0;
}
