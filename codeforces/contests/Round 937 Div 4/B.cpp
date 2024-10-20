#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
        int n;
        cin >> n;
       string hash = "##";
       string dot ="..";
       int count = -1;
        for (int i = 0; i < 2*n; i++) {
            if (i % 2 == 0) {
                count++;
            }

            for (int j = 0; j < n; j++) {
                if (count % 2 == 0) {
                    if (j % 2 == 0) {
                        cout << hash;
                    } else {
                        cout << dot;
                    }
                } else {
                    if (j % 2 == 0) {
                        cout << dot;
                    } else {
                        cout << hash;
                    }
                }
            }
            cout << endl;
        }
    }
}