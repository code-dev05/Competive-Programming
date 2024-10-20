#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
        int n;
        cin >> n;
        map<int, vector<int>> m;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            m[u].push_back(v);
            m[v].push_back(u);
        }
        vector<int> a(n + 1);  
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            if (u == v) {
                cout << (a[u] ^ 0) << endl;
                continue;
            }
            int cost = 0;
            stack<tuple<int, int, int>> s;
            unordered_set<int> visited;
            s.push({u, a[u], 1});
            visited.insert(u);
            bool found = false;

            while (!s.empty() && !found) {
                auto [cur, cur_cost, idx] = s.top();
                s.pop();
                for (int node : m[cur]) {
                    if (visited.find(node) == visited.end()) {
                        visited.insert(node);
                        int new_cost = cur_cost + (a[node] ^ (idx));
                        if (node == v) {
                            cost = new_cost;
                            found = true;
                            break;
                        }
                        s.push({node, new_cost, idx + 1});
                    }
                }
            }
            cout << cost << endl;
        }
    }
    return 0;
}
