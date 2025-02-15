#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 1) {
        cout << 1 << endl;
        return;
    }
    cout << b - a << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
