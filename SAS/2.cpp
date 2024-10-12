#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll m, n, k;
    cin >> n >> m >> k;
    vector<int> ap(n), nap(m);
    int count = 0;
    for (int i = 0; i < n; i++)
        cin >> ap[i];
    for (int j = 0; j < n; j++)
        cin >> nap[j];
    sort(ap.begin(), ap.end());
    sort(nap.begin(), nap.end());
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && nap[j] < ap[i] - k)
            j++;
        if (j < m && nap[j] <= ap[i] + k)
        {
            count++;
            j++;
        }
    }
    cout << count << "\n";
    return 0;
}
