#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> arr(3);
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            arr[0] += 5;
        } else if (arr[0] == arr[1]) {
            arr[0] += 5;
        } else if (arr[1] == arr[2]) {
            arr[0] += 5;
        } else {
            arr[0] += 3;
            arr[1] += 2;
        }
        int res = 1;
        for (int i : arr) {
            res *= i;
        }
        if (arr[0] != arr[1] && arr[1] != arr[2]) {
            arr[0] -= 1;
            arr[1] += 1;
        }
        int temp = 1;
        for (int i : arr) {
            temp *= i;
        }
        cout << max(res, temp) << endl;
    }
}