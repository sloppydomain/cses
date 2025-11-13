#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> ans;
    int count = 0;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int n;
        cin >> n;
        ans.push_back(n);
    }
    sort(ans.begin(), ans.end());
    for (int j = 0; j < x; j++)
    {
        if (ans[j] != ans[j + 1])
            count++;
    }
    cout << count << endl;
    return 0;
}
