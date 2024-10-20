#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] != 1) count += (arr[i] - 1);
        }
        count += (n - arr[arr.size() - 1]);
        cout << count << endl;
    }
}