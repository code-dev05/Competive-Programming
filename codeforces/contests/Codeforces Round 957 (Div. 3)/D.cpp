#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<char> arr(n+1);
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
        }
        int flag = 1;
        int idx = 0;
        while (idx <= n) {
            if (idx == 0 || arr[idx] == 'L') {
                for (int temp = idx+1; temp <= idx + m; temp++) {
                    
                }
            } else if (arr[idx + 1] == 'W') {

            }
        }
    }
}