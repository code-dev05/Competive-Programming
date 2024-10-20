#include <bits/stdc++.h>

using namespace std;

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}

void printMatrix(vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<char>>& matrix, vector<vector<int>>& vis, int i, int j) {
    int n = matrix.size();
    int m = matrix[0].size();
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};
    stack<pair<int, int>> s;
    s.push({i, j});
    while (!s.empty()) {
        auto [r, c] = s.top();
        s.pop();
        vis[r][c] = 1;
        for (int x = 0; x < 4; x++) {
            int newI = r + di[x];
            int newJ = c + dj[x];
            if (isValid(newI, newJ, n, m) && vis[newI][newJ] == 0 && matrix[newI][newJ] == '.') {
                s.push({newI, newJ});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' && vis[i][j] == 0) {
                count++;
                dfs(matrix, vis, i, j);
            }
        }
    }
    cout << count;
}