#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    vector<vector<string>> dp(m+1, vector<string>(n+1, ""));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + s[i-1];
            else if (dp[i-1][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i][j-1];
        }
    }
    cout << dp[m][n];
}