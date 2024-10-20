#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& children, vector<int>& childs, int i) {
    if (children[i].empty()) return 1;
    int count = 0;
    for (int c : children[i]) {
        count += dfs(children, childs, c);
    }
    childs[i] = count;
    return count+1;
}

int main() {
    int n;
    cin >> n;
    int temp;
    vector<vector<int>> children(n+1);
    for (int i = 2; i<= n; i++) {
        cin >> temp;
        children[temp].push_back(i);
    }
    vector<int> numChilds(n+1, 0);
    dfs(children, numChilds, 1);
    for (int i = 1; i <= n; i++) {
        cout << numChilds[i] << " ";
    }
}