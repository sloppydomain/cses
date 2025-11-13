#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll n, t, s = 0;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> t;
        s += t;
    }
    cout << (n * (n + 1) / 2 - s) << " ";
    return 0;
}