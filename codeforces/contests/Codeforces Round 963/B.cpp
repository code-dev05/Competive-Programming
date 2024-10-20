#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    sort(arr.begin(), arr.end());
    int odd = 0;
    int even = 0;
    int count = 0;
    int mark = 0;
    while (odd < n && even < n) {
        while (odd < n && arr[odd] % 2 == 0) odd++;
        while (even < n && arr[even] % 2 != 0) even++;
        if (odd == n || even == n) break;
        if (even < odd) {
            count++;
            even++;
        } else {
            mark = even;
            odd++;
        }
    }
    for (int i = mark; i < n; i++) {
        if (arr[i] % 2 == 0) count += 2;
    }
    // cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
