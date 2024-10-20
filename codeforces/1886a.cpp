#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int flag = 0;
        for (int x = 1; x < n; x++) {
            if (x % 3 == 0) {
                continue;
            }
            for (int y = 1; y < n; y++) {
                if (y % 3 == 0) {
                    continue;
                }
                for (int z = 1; z < n; z++) {
                    if (z % 3 == 0) {
                        continue;
                    }
                    if (x == y || x == z || y == z) {
                        continue;
                    }
                    if (x + y + z == n) {
                        cout << "YES" << endl;
                        cout << x << " " << y << " " << z << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            else {
                cout << "NO";
                break;
            }
        }
    }
}