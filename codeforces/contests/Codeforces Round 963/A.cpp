#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[] = {0, 0, 0, 0};
    int count = 0;
    for (char c : s) {
        if (c != '?') {
            if (arr[c - 'A'] < n) {
                count++;
                arr[c - 'A']++;
            }
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
