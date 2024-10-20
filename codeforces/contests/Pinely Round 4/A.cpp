#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i % 2 == 0) {
            arr.push_back(x);
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    cout << arr[0] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
