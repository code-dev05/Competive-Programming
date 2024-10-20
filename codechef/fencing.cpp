#include <bits/stdc++.h>
using namespace std;

long long int dfs(vector<vector<long long int>>& mat, vector<vector<long long int>>& vis, long long int x, long long int y) {
    long long int n = mat.size();
    long long int m = mat[0].size();
    long long int count = 0;
    long long int di[] = {0, 1, 0, -1};
    long long int dj[] = {1, 0, -1, 0};
    stack<pair<long long int, long long int>> s;
    s.push({x, y});
    while (!s.empty()) {
        auto [i, j] = s.top();
        s.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        for (long long int k = 0; k < 4; k++) {
            long long int newI = i + di[k];
            long long int newJ = j + dj[k];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m) {
                if (mat[newI][newJ] == 0) count++;
                else if (!vis[newI][newJ]) {
                    s.push({newI, newJ});
                }
            } else count++;
        }
    }
    return count;
}

void solve() {
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long int>> mat(n, vector<long long int>(m, 0));
    while (k--) {
        long long int t1, t2;
        cin >> t1 >> t2;
        mat[t1-1][t2-1] = 1;
    }
    long long int count = 0;
    vector<vector<long long int>> vis(n, vector<long long int>(m, 0));
    for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < m; j++) {
            if (mat[i][j] == 1 && !vis[i][j]) {
                count += dfs(mat, vis, i, j);
            }
        }
    }
    cout << count << endl;
}

int main() {
    long long int T;
    cin >> T;
    while (T--) {
        solve();
    }
}