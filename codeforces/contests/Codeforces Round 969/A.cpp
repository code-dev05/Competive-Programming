#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if (r - l < 2 || (r - l == 2 && l % 2 == 0)) {
        cout << 0 << endl;
        return;
    }
    int count = 0;
    int i = l;
    while (i <= r) {
        if (i % 2 == 0) i++;
        else {
            i += 3;
            if (i <= r + 1) count++;
        }
    }
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
