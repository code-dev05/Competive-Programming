#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

void solve(string& s) {
    string c="";
    string num="";
    int n=-1;
    int i = 0;
    while (i < s.size()) {
        if (isalpha(s[i]) && c!="" && num!="") {
            n = stoi(num);
            for (int x = 0; x < n; x++) cout << c;
            c = "";
            num = "";
        }
        if (isdigit(s[i])) {
            num += s[i];
        } else {
            c += s[i];
        }
        i++;
    }
    n = stoi(num);
    for (int x = 0; x < n; x++) cout << c;
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}