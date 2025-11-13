#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> qa;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
                d[i][j] = 0;
                qa.push({i, j});
            }
        }
    }
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};
    
    while (!qa.empty()) {
        auto cur = qa.front();
        qa.pop();
        int i = cur.first, j = cur.second;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (d[ni][nj] == -1 && grid[ni][nj] == '.') {
                    d[ni][nj] = d[i][j] + 1;
                    parent[ni][nj] = {i, j};
                    qa.push({ni, nj});
                }
            }
        }
    }
 
    vector<vector<int>> md(n, vector<int>(m, -1));
    queue<pair<int, int>> qm;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                md[i][j] = 0;
                qm.push({i, j});
            }
        }
    }
    
    while (!qm.empty()) {
        auto cur = qm.front();
        qm.pop();
        int i = cur.first, j = cur.second;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (grid[ni][nj] != '#' && md[ni][nj] == -1) {
                    md[ni][nj] = md[i][j] + 1;
                    qm.push({ni, nj});
                }
            }
        }
    }
    pair<int, int> e = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (d[i][j] != -1 && (md[i][j] == -1 || d[i][j] < md[i][j])) {
                    e = {i, j};
                    break;
                }
            }
        }
        if (e.first != -1) break;
    }
    
    if (e.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path;
        int i = e.first, j = e.second;
        while (make_pair(i, j) != start) {
            auto par = parent[i][j];
            for (int k = 0; k < 4; k++) {
                if (par.first + di[k] == i && par.second + dj[k] == j) {
                    path.push_back(dir[k]);
                    break;
                }
            }
            i = par.first;
            j = par.second;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    }
    return 0;
}