#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    for (int i = 1; i <= min(a.size(), b.size()); i++) {
        if (a[i-1] != b[i-1]) {
            cout << i;
            return 0;
        }
    }
    if (a.size() != b.size()) {
        int n1 = a.size();
        int n2 = b.size();
        cout << min(n1, n2) + 1;
        return 0;
    }
    cout << 0;
    return 0;
}