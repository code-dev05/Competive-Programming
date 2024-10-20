#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int operations = 0;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    while (n > 0) {
        operations += n % k;
        n /= k;
    }
    cout << operations << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
