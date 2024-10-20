#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin, s);
    vector<string> words;
    string temp = "";
    for (char c : s) {
        if (c == ' ') {
            words.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    words.push_back(temp);
    unordered_map<string, int> m;
    for (string t : words) {
        sort(t.begin(), t.end());
        m[t]++;
    }
    vector<int> ans;
    for (auto i : m) {
        ans.push_back(i.second);
    }
    sort(ans.begin(), ans.end(), [](int a, int b) {
        return a > b;
    });
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}