#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define endl '\n'
 
const ll mod = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    vector<int> dist(n + 1, -1e10);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (dist[j] != -1e10){
                for (pair<int, int> x : graph[j]){
                    int v = x.first;
                    int w = x.second;
                    if (dist[j] + w > dist[v])
                        dist[v] = dist[j] + w;
                }
            }
        }
    }
    for (int u = 1; u < n + 1; u++){
        if (dist[u] != -1e10){
            for (pair<int, int> x : graph[u]){
                int v = x.first;
                int w = x.second;
                if (dist[u] + w > dist[v]){
                    queue<int> q;
                    q.push(u);
                    vector<bool> visited(n + 1, false);
                    while (!q.empty()){
                        int node = q.front();
                        q.pop();
                        if (node == n){
                            cout << -1;
                            exit(0);
                        }
                        visited[node] = true;
                        for (pair<int, int> x : graph[node]){
                            if (!visited[x.first]){
                                q.push(x.first);
                            }
                        }
                    }
                }
            }
        }
    }
 
    cout << dist[n];
 
    return 0;
}