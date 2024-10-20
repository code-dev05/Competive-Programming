#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> m;
    for (int i = 0; i < 3*n; i++) {
        string s;
        int count;
        cin >> s >> count;
        m[s] += count;
    }
    vector<pair<string, int>> arr(m.begin(), m.end());
    sort(arr.begin(), arr.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    });
    for (auto i : arr) {
        cout << i.second << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
