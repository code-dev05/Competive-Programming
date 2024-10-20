#include <bits/stdc++.h>
using namespace std;

int ascending(vector<int> arr) {
    int swaps = 0;
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
                swaps++;
            }
        }
        if (!swapped) break;
    }
    return swaps;
}

int descending(vector<int> arr) {
    int swaps = 0;
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j+1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
                swaps++;
            }
        }
        if (!swapped) break;
    }
    return swaps;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int res = min(ascending(arr), descending(arr));
    cout << res;
}