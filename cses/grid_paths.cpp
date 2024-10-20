#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll solve(ll n, vector<string>& grid) {
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    ll mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') dp[i][j] = 0;
            else {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
            dp[i][j] %= mod;
        }
    }
    return dp[n-1][n-1];
}

int main() {
    ll n;
    cin >> n;
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];
    cout << solve(n, grid) << endl;
}