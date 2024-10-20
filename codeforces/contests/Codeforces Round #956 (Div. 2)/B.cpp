#include <bits/stdc++.h>

using namespace std;

void change(char& a) {
    if (a == '0') a = '1';
    else if (a == '1') a = '2';
    else if (a == '2') a = '0';
}

int main() {
    int T;
    cin >> T;
    int m, n;
    for (int x = 0; x < T; x++) {
        cin >> m >> n;
        vector<string> arr1(m);
        vector<string> arr2(m);
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (char j = 0; j < n; j++) {
                if (arr1[i][j] != arr2[i][j]) count++;
            }
        }
        cout << count;
    }
}