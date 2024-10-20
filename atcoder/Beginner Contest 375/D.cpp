#include <bits/stdc++.h>
using namespace std;

int solve(string& s, map<pair<string, int>, int> dp, int n, int ind, string temp) {
    if (temp.size() == 3) {
        if (temp[0] == temp[2]) return 1;
        return 0;
    }

    if (ind >= n) return 0;

    if (dp[{temp, ind}] != 0) return dp[{temp, ind}];
    
    int count = 0;

    count += solve(s, dp, n, ind+1, temp);
    count += solve(s, dp, n, ind+1, temp+s[ind]);
    return dp[{temp, ind}] = count;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<pair<string, int>, int> dp;
    cout << solve(s, dp, n, 0, "");
}