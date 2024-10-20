#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    for (int x = 0; x < T; x++) {
        cin >> n;
         vector<int> arr1(n);
         vector<int> arr2(n);
         vector<int> arr3(n);
         int tot = 0;
         for (int i = 0; i < n; i++) {
            cin >> arr1[i];
            tot += arr1[i];
         }
         for (int i = 0; i < n; i++) {
            cin >> arr2[i];
         }
         for (int i = 0; i < n; i++) {
            cin >> arr3[i];
         }
         
    }
}