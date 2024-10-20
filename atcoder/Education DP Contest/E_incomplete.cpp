#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long w, v;
};

int main() {
    long long int n, w;
    cin >> n >> w;
    vector<Item> arr(n+1);
    for (long long int i = 0; i < n; i++) cin >> arr[i].w >> arr[i].v;
    vector<vector<long long int>> dp(n, vector<long long int>(w+1, 0));
    for (long long int i = 0 ; i <= w; i++) {
        if (i < arr[0].w) dp[0][i] = 0;
        else dp[0][i] = arr[0].v;
    }
    for (long long int i = 1; i < n; i++) {
        for (long long int j = 0; j <= w; j++) {
            if (j < arr[i].w) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], arr[i].v + dp[i-1][j - arr[i].w]);
            }
        }
    }

    cout << dp[n-1][w];
}