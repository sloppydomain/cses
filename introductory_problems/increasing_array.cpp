#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll n, count = 0;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            while (arr[j + 1] != arr[j])
            {
                arr[j + 1] += 1;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
