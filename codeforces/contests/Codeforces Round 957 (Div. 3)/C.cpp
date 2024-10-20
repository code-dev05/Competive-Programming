#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        int i = 0;
        for (int temp = n; temp >= k; temp--) {
            arr[i] = temp;
            i++;
        }
        int j = n - 1;
        for (int temp = m; temp >= 1; temp--) {
            arr[j] = temp;
            j--;
        }
        for (int temp = i; i <= j; i++) {
            arr[i] = arr[i - 1] - 1;
        }
        for (int temp : arr) {
            cout << temp << " ";
        }
        cout << endl;
    }
}