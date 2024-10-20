#include <bits/stdc++.h>

using namespace std;

void solve(int n, int q, vector<int>& m, vector<pair<int, int>>& p) {
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int k = 0; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            int j = i + k;
            if (j > n) continue;
            if ((j - i) % 2 == 0) dp[i][j] = -1;
            else if (k == 1) dp[i][j] = m[i];
            else {
                dp[i][j] = dp[i][i+1] - dp[i+1][j-1] + dp[j-1][j];
            }
        }
    }

    for (auto x : p) {
        cout << dp[x.first][x.second] << endl;
    }
} 

int main() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> m(n);
    vector<pair<int, int>> p(q);
    for (int i = 0; i < n-1; i++) cin >> m[i+1];
    for (int i = 0; i < q; i++) cin >> p[i].first >> p[i].second;
    solve(n, q, m, p);
}
