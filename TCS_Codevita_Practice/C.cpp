#include <bits/stdc++.h>
using namespace std;

int solve(string& s, int n, int i, char prev = ' ', int count = 0) {
    if (count == 3) return 1;
    int res = 0;
    for (int j = i; j < n; j++) {
        if (s[j] != prev) {
            res += solve(s, n, j, s[j], count+1);
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int res = solve(s, n, 0);
    cout << n;
}