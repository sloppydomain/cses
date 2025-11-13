#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = 1, max_ = 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        count = 1;
        max_ = max(max_, count);
    }
    cout << max_;
    return 0;
}