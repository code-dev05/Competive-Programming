#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int xorSum = 0;
    for (int i : arr) {
        xorSum ^= i;
    }
    int ans = xorSum;
    for (int i : arr) {
        int temp = xorSum ^ i;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
