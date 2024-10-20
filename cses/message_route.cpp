#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

void printReverse(vector<int>& parent, int n) {
    if (parent[n] == -1) {
        cout << n << " ";
    } else {
        printReverse(parent, parent[n]);
        cout << n << " ";
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

void shortest_path(vector<vector<int>>& graph, int n) {
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    dist[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : graph[node]) {
            if (dist[node] + 1 < dist[i]) {
                dist[i] = dist[node] + 1;
                parent[i] = node;
                q.push(i);
            }
        }
    }
    // for (int i : parent) cout << i << " ";

    if (parent[n] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[n] << endl;
        printReverse(parent, n);
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
    // printMatrix(graph);

    shortest_path(graph, n);
}