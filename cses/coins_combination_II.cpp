#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll solve(ll n, ll x, vector<ll>& coins) {
    ll mod = 1e9 + 7;
    vector<ll> dp(x+1);
    dp[0] = 1;
    for (ll coin : coins) {
        for (ll i = 1; i <= x; i++) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
                dp[i] %= mod;
            }
        }
    }
    return dp[x];
}

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    cout << solve(n, x, coins) << endl;
}