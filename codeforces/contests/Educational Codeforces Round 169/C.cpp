#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });
    if (n % 2 == 0) {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a += arr[i];
            else b += arr[i];
        }
        cout << max(a-b-k, 0) << endl;
    } else {
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) continue;
            else if (i % 2 == 0) {
                diff += (arr[i] - arr[i+1]);
            } 
        }
        cout << arr[n-1]+max(diff - k, 0) << endl;
    }
}
//hello
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
