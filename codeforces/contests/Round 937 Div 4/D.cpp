#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isBinDec(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;            
        }
    }
    return true;
}

bool inArray(int n, vector<int> arr) {
    for (int i : arr) {
        if (n == i) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                arr.push_back(i);
            }
        }

        bool flag = false;

        for (int factor : arr) {
            int other;
            if (isBinDec(factor)) {
                other = n / factor;
                if (inArray(other, arr)) {
                    if (isBinDec(other)) {
                        flag = true;
                        break;
                    }
                }
            }
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}