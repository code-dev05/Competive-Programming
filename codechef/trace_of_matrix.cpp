#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--) {
        int temp = 0;
        int j = 0;
        for (int k = i; k < n; k++) {
            temp += mat[k][j];
            j++;
        }
        maxi = max(maxi, temp);
    }
    for (int j = 0; j < n; j++) {
        int i = 0;
        int temp = 0;
        for (int k = j; k < n; k++) {
            temp += mat[i][k];
            i++;
        }
        maxi = max(maxi, temp);
    }
    cout << maxi << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}