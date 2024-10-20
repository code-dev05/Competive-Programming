#include <bits/stdc++.h>

using namespace std;

void rotateRightByOne(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        if (!row.empty()) {
            int lastElement = row.back();
            row.pop_back();
            row.insert(row.begin(), lastElement);
        }
    }
}

void rotateMatrixRows(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    std::vector<int> firstRow = matrix[0];

    for (int i = 1; i < numRows; ++i) {
        matrix[i - 1] = matrix[i];
    }

    matrix[numRows - 1] = firstRow;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        if (m == 1 && n == 1) cout << -1 << endl;
        else {
            rotateRightByOne(matrix);
            rotateMatrixRows(matrix);
            printMatrix(matrix);
        }
    }
}
