#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

void shortest_path(vector<vector<pii>> graph, int n) {
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        for (auto [i, j] : graph[node]) {
            if (dist[node] + j < dist[i]) {
                dist[i] = dist[node] + j;
                s.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n+1);
    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >>temp3;
        graph[temp1].push_back({temp2, temp3});
        graph[temp2].push_back({temp1, temp3});
    }

    shortest_path(graph, n);
}