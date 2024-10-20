#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> arr1(arr.begin(), arr.begin() + k);
    vector<int> arr2(arr.end() - k, arr.end());
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int maxi = max(arr1[((arr1.size() + 1) - 1) / 2], arr2[((arr2.size() + 1) / 2) - 1]);
    for (int i = k; i < arr.size() - k; i++) {
        maxi = max(maxi, arr[i]);
    }
    cout << maxi;
}