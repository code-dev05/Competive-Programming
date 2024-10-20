#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;
    dp[2] = abs(arr[1] - arr[2]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(arr[i-1] - arr[i]), dp[i-2] + abs(arr[i-2] - arr[i]));
    }
    cout << dp[n];
}