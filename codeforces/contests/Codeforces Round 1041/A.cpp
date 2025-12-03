#include <bits/stdc++.h>

using namespace std;

int firstMissingNonNegative(std::vector<int>& arr, int l, int r) {
    std::unordered_set<int> seen;
    for (int i = l; i <= r; i++) {
        int num = arr[i];
        if (num >= 0) {
            seen.insert(num);
        }
    }

    int i = 0;
    while (true) {
        if (seen.find(i) == seen.end()) {
            return i;
        }
        i++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> d;

    for (int num : arr) {
        if (num != -1) {
            d.insert(num);
        }
    }
    if (d.size() == 0) {
        cout << "YES" << endl;
        return;
    }
    if (d.size() > 1) {
        cout << "NO" << endl;
        return;
    } else if (d.size() == 1 && *d.begin() != 0) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
