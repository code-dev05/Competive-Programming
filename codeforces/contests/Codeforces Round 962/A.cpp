#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    res += (n / 4);
    n = n % 4;
    res += (n / 2);
    n = n % 2;
    cout << res << endl;    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
