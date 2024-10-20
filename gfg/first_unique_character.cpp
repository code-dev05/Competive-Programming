#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(26, 0);
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        arr[c - 'a']++;
    }
    char ans;
    for (char c : s) {
        if (arr[c - 'a'] == 1) {
            ans = c;
            break;
        }
    }
    cout << ans;
}