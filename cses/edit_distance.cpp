#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(string& a, string& b, int i, int j, vector<vector<ll>>& dp) {
  if (j < 0) return i+1;
  if (i < 0 ) return j+1;
  if (dp[i][j] != -1) return dp[i][j];
  if (a[i] == b[j]) return 0 + solve(a, b, i-1, j-1, dp);
  else {
    ll minI = INT_MAX;
    minI = min(minI, 1 + solve(a, b, i, j-1, dp));
    minI = min(minI, 1 + solve(a, b, i-1, j, dp));
    minI = min(minI, 1 + solve(a, b, i-1, j-1, dp));
    return dp[i][j] = minI;
  }
}

int main() {
  string a, b;
  cin >> a >> b;
  int na = a.size();
  int nb = b.size();
  vector<vector<ll>> dp(na, vector<ll>(nb, -1));
  cout << solve(a, b, na-1, nb-1, dp);
}
