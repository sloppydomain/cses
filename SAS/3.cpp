#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x, w;
    cin >> x >> w;
    vector<int> cw(x);
    for (int i = 0; i < x; i++)
    {
        cin >> cw[i];
    }
    int ans = 0;
    sort(cw.begin(), cw.end());
    for (int i = 0, j = x - 1; i < j; i++)
    {
        while (i < j && cw[i] + cw[j] > w)
            --j;
        if (i >= j)
        {
            break;
        }
        ans++;
        j--;
    }
    cout << x - ans << endl;
    return 0;
}
