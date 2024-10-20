#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& mat, int m, int n) {
    vector<vector<int>> result(n, vector<int>(m));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            result[c][r] = mat[r][c];
        }
    }
    return result;
}

vector<vector<int>> rev_rows(const vector<vector<int>>& mat, int m, int n) {
    vector<vector<int>> result(m, vector<int>(n));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            result[r][c] = mat[m - r - 1][c];
        }
    }
    return result;
}

vector<vector<int>> rev_cols(const vector<vector<int>>& mat, int m, int n) {
    vector<vector<int>> result(m, vector<int>(n));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            result[r][c] = mat[r][n - c - 1];
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int corner;
        cin >> corner;
        vector<vector<int>> ans;
        if (corner == 2 || corner == 0) {
            ans = transpose(mat, m, n);
            ans = rev_cols(ans, n, m);
            ans = rev_rows(ans, n, m);
        } 
        if (corner == 3 || corner == 1) {
            ans = transpose(mat, m, n);
        }
        for (int r = 0; r < ans.size(); r++) {
            for (int c = 0; c < ans[0].size(); c++) {
                cout << ans[r][c] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
