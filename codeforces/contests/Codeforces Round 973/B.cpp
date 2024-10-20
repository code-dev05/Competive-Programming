#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        dp[i][i+1] = arr[i+1] - arr[i];
    }
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
