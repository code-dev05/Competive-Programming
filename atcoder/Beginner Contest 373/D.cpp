#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<long long int> ans(n+1);
    vector<vector<pair<long long int, long long int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        long long int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        graph[t1].push_back({t2, t3});
    }
    
}