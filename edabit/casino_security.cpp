#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (c == 'x') continue;
        else {
            if (st.empty()) st.push(c);
            else if (c == 'T') {
                if (st.top() == '$') {
                    cout << "ALARM\n";
                    return;
                } else st.push(c);
            } else if (c == 'G') {
                st.push(c);
            } else if (c == '$') {
                if (st.top() == 'T') {
                    cout << "ALARM\n";
                    return;
                } else {
                    st.push(c);
                }
            }
        }
    }
    cout << "SAFE\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}