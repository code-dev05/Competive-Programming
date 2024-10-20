#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int minimizeCoins(int target, const vector<int>& coins) {
    vector<int> dp(target + 1, INF);
    dp[0] = 0;
    
    for (int coin : coins) {
        for (int amount = coin; amount <= target; ++amount) {
            dp[amount] = min(dp[amount], dp[amount - coin] + 1);
        }
    }
    
    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    int result = minimizeCoins(target, coins);
    cout << result << endl;
    
    return 0;
}
