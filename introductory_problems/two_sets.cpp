#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    
    ll sum = n * (n + 1) / 2;
    
    if (sum % 2 == 1) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES" << endl;
        
        ll subsum = sum / 2;
        vector<int> s1, s2;
        
        for (ll i = n; i >= 1; i--) {
            if (i <= subsum) {
                subsum -= i;
                s1.push_back(i);
            } else {
                s2.push_back(i);
            }
        }
        
        cout << s1.size() << endl;
        for (auto i : s1)
            cout << i << " ";
        cout << endl;
        
        cout << s2.size() << endl;
        for (auto i : s2)
            cout << i << " ";
        
        return 0;
    }
}
