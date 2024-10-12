#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int N = 200005;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
void hello() {
    string s;
    cin >> s;
    int n = s.length();
    int f[26];
    memset(f, 0, sizeof(f));
    for(int i = 0; i < n; i++) {
        f[s[i] - 'A']++;
    }
    int oddCount = 0;
    for(int i = 0; i < 26; i++) {
        if(f[i] & 1) {
            oddCount++;
        }
    }
    if(oddCount >= 2 || (oddCount > 0 && n % 2 == 0)) {
        cout << "NO SOLUTION";
    } else {
        char ans[n];
        int k = 0;
        char m = ' ';
        for(int i = 0; i < 26; i++) {
            if(f[i]) {
                for(int j = 0; j < f[i] / 2; j++) {
                    ans[k] = (char)(i + 'A');
                    ans[n - k - 1] = (char)(i + 'A');
                    k++;
                }
                if(f[i] % 2 == 1) {
                    m = (char)(i + 'A');
                }
            }
            if(k == n) {
                break;
            }
        }
        if(m != ' ') {
            ans[n / 2] = m;
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i];
        }   
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        hello();
    }
    return 0;
}
