#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a && c > b) {
            cout << "STAIR\n";
        } else if (b > a && b > c) {
            cout << "PEAK\n";
        } else {
            cout << "NONE\n";
        }
    }
}