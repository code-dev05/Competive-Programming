#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long int MOD = 1e9 + 7;
    long long int m, n;
    cin >> m >> n;
    vector<string> grid(m);
    for (long long int i = 0; i < m; i++) cin >> grid[i];
    vector<vector<long long int>> dp(m, vector<long long int>(n, 0));
    dp[0][0] = 1;
    for (long long int i = 0; i < m; i++) {
        for (long long int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if (j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
            if (grid[i][j] == '#') dp[i][j] = 0;
        }
    }
    std::cout << dp[m-1][n-1] << endl;
}