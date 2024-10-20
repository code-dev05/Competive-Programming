#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        dp[1][i] = arr[1][i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        maxi = max(maxi, dp[n][i]);
    }
    cout << maxi;
}