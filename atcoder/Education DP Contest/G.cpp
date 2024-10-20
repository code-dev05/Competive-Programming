#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& graph, vector<int>& dp, int i) {
    if (dp[i] != -1) return dp[i];
    int count = 0;
    for (int x : graph[i]) {
        count = max(count, dfs(graph, dp, x) + 1);
    }
    return dp[i] = count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> dp(n+1, -1);
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != -1) maxi = max(maxi, dp[i]);
        else maxi = max(maxi, dfs(graph, dp, i));
    }
    cout << maxi;
}