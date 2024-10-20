#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) cout << -1 << endl;
    else if (n == 1) cout << 1 << endl;
    else {
        int i = n;
        while (i != 1) {
            cout << i << " ";
            i -= 2;
        }
        cout << 1 << " " << 2 << " ";
        i = 4;
        while (i < n) {
            cout << i << " ";
            i+= 2;
        }
    }    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
