#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> grid(n);
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int reducedSize = n / k;
    vector<string> reducedGrid(reducedSize, string(reducedSize, '0'));

    for (int i = 0; i < reducedSize; i++) {
        for (int j = 0; j < reducedSize; j++) {
            char value = grid[i * k][j * k];
            reducedGrid[i][j] = value;
        }
    }

    for (const string& row : reducedGrid) {
        cout << row << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
