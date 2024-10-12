#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll a1 = i * i;
        ll a2 = a1 * (a1 - 1) / 2;
        if (i > 2)
            a2 = a2 - 4 * (i - 1) * (i - 2);
        cout << a2 << endl;
    }
    return 0;
}