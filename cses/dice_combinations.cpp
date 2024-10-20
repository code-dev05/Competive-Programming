#include <bits/stdc++.h>

using namespace std;

long long sol(long long n, vector<long long>& dp) {
    long long mod = 1e9 + 7;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    return dp[n];
}

int main() {
    long long n;
    cin >> n;
    vector<long long> dp(n+1, 0);   
    long long res = sol(n, dp);
    cout << res % ((long long)pow(10, 9) + 7);
}