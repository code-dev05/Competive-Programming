#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& group, int n, int x) {
    queue<int> q;
    q.push(x);
    int flag = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : graph[node]) {
            if (group[i] == -1) {
                if (group[node] == 1) group[i] = 2;
                else group[i] = 1;
                q.push(i);
            } else if (group[i] == group[node]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0) {
        group[0] = 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    int temp1, temp2;
    for (int i = 1; i <= m; i++) {
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    vector<int> group(n+1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (group[i] == -1) {
            group[i] = 1;
            bfs(graph, group, n, i);
        }
    }
    if (group[0] == 1) cout << "IMPOSSIBLE";
    else {
        for (int i = 1; i <= n; i++) cout << group[i] << " ";
    }
}