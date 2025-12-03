#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<char> s(n);
    for (int i = 1; i <= n; i++) cin >> s[i];

    if (x == 1 || x == n) {
        cout << 1 << endl;
        return;
    }

    int l = -1, r = -1;
    for (int i = x - 1; i > 0; i--) {
        if (s[i] == '#') {
            l = i;
            break;
        }
    }

    for (int i = x + 1; i <= n; i++) {
        if (s[i] == '#') {
            r = i;
            break;
        }
    }

    if (l == -1 && r == -1) {
        cout << 1 << endl;
        return;
    }

    if (x < n - x + 1) {
        
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
