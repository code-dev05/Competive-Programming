#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}

void bfs(vector<vector<char>>& grid, int n, int m, pii si, pii ei) {
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};
    char dir[] = {'U', 'R', 'D', 'L'};
    queue<tuple<int, int, int, string>> q;
    q.push({si.first, si.second, 0, ""});
    string finalPath;
    int finalCount = INT_MAX;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    while (!q.empty()) {
        auto [r, c, count, path] = q.front();
        q.pop();
        vis[r][c] = 1;
        for (int x = 0; x < 4; x++) {
            int newI = r + di[x];
            int newJ = c + dj[x];
            if (isValid(newI, newJ, n, m) && (grid[newI][newJ] == '.' || grid[newI][newJ] == 'B') && vis[newI][newJ] == 0) {
                if (newI == ei.first && newJ == ei.second) {
                    // get shortest path
                    if (count + 1 < finalCount) {
                        finalCount = count+1;
                        finalPath = path+dir[x];
                    }
                } else {
                    q.push({newI, newJ, count+1, path+dir[x]});
                }
            }
        }
    }
    if (finalCount == INT_MAX) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        cout << finalCount << endl;
        cout << finalPath << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    pii si, ei;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') si = {i, j};
            if (grid[i][j] == 'B') ei = {i, j};
        }
    }
    bfs(grid, n, m, si, ei);
}