#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() < 3) {
        cout << "No";
    } else {
        if (s.substr(s.size() - 3) == "san") {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
}