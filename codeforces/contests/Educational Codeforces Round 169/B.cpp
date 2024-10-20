#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (l > R || L > r) {
        cout << 1 << endl;
        return;
    }

    int count = 0;
    int maxL = max(l, L);
    int minR = min(r, R);
    count = minR - maxL+1;
    if (r == R) count--;
    if (l != L) count++;
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
