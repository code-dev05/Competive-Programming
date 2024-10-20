#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[j][i];
}

void reverseArr(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        reverse(A[i].begin(), A[i].end());
    }
}

void printMatrix(vector<vector<int>> arr) {
    for (auto i : arr) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(n, vector<int>(m, 0));
    int k;
    cin >> k;
    if (k == 1) {
        transpose(A, B);
        printMatrix(B);
    } else if (k == 2) {
        reverseArr(A);
        transpose(A, B);
        reverseArr(B);
        printMatrix(B);
    } else if (k == 3) {
        transpose(A, B);
        printMatrix(B);
    } else if (k == 0) {

    }

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}