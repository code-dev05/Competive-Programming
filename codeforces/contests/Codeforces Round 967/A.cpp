#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    int temp;
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp]++;
        maxCount = max(maxCount, m[temp]);
    }
    cout << n - maxCount << endl;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
