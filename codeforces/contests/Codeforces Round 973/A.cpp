#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int t = min(x, y);
    if (n % t == 0) cout << n / t << endl;
    else cout << n / t + 1 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
