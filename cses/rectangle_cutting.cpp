#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
    for (int i = 1; i <=a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) dp[i][j] = 0;
            else if (i < j) {
                dp[i][j] = 1 + dp[i][j-i];
            } else {
                dp[i][j] = 1 + dp[i-j][j];
            }
        }
    }
    // printMatrix(dp);
    cout << dp[a][b];
}