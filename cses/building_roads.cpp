#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& vis, int x) {
    stack<int> s;
    s.push(x);
    while (!s.empty()) {
        int i = s.top();
        s.pop();
        vis[i] = 1;
        for (int j : graph[i]) {
            if (vis[j] == 0) {
                s.push(j);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    int temp1, temp2;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    int count = 0;
    vector<int> vis(n+1);
    vector<int> group;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            count++;
            if (i != 1) group.push_back(i);
            dfs(graph, vis, i);
        }
    }
    cout << count - 1 << endl;
    for (int x : group) {
        cout << 1 << " " << x << endl;
    }
}