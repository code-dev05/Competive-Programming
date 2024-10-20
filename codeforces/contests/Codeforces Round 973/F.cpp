#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& graph, vector<int>& out, vector<int>& vis, int i, int j) {
    if (out[i] == 0) return 1;
    else if (out[j] == 0) return 0;

    int res = 0;
    for (int x : graph[i]) {
        for (int y : graph[j]) {
            if (!vis[x] && !vis[y]) {
                vis[x] = 1;
                vis[y] = 1;
                for (int t : graph[x]) out[t]--;
                for (int t : graph[y]) out[t]--;
                if (dfs(graph, out, vis, x, y) == 1) res = 1;
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<int> out(n+1, 0);
    for (int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
        out[t1]++;
        out[t2]++;
    }
    int u, v;
    cin >> u >> v;
    vector<int> vis(n+1, 0);
    vis[1] = 1;
    vis[u] = 1;
    for (int i : graph[u]) {
        out[i]--;
    }
    int res = dfs(graph, out, vis, 1, u);
    if (res == 1) cout << "Bob";
    else cout << "Alice";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
