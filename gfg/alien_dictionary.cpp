#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    for (auto i : matrix) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

string findOrder(vector<string>& dict, int n, int k) {
    // code here
    vector<vector<int>> graph(k);
    for (int i = 0; i < n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        for (int j = 0; j < min(s1.size(), s2.size()); j++) {
            if (s1[j] != s2[j]) {
                graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> indegrees(k);
    for (int i = 0; i < k; i++) {
        for (int j : graph[i]) {
            indegrees[j]++;
        }
    }

    
    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegrees[i] == 0) q.push(i);
    }
    
    string ans = "";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans += ('a' + node);
        for (int i : graph[node]) {
            indegrees[i]--;
            if (indegrees[i] == 0) q.push(i);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];
    cout << findOrder(dict, n, k);
}