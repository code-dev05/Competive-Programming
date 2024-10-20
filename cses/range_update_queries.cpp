#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 2) {
            int k;
            cin >> k;
            cout << arr[k-1] << endl;
        }
        else {
            int a, b, u;
            cin >> a >> b >> u;
            for (int j = a; j <= b; j++) {
                arr[j] += u;
            }
        }
    }
}