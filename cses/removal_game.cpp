  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (long long i = 0; i < n; i++) dp[i][i] = arr[i];
    
    long long sum = 0;
    for (long long i = 0; i < n; i++) sum += arr[i];

    for (long long i = 0; i < n-1; i++) {
      dp[i][i+1] = max(arr[i], arr[i+1]) - min(arr[i], arr[i+1]);
    }
    
    for (long long k = 3; k <= n; k++) {
      for (long long i = 0; i + k - 1 < n; i++) {
        long long j = i + k - 1;
        dp[i][j] = max(dp[i][i] - dp[i+1][j], dp[j][j] - dp[i][j-1]);
      }
    }

    cout << (sum + dp[0][n-1]) / 2;

  }