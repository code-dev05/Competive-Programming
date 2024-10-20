#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int arr[26];
    int i = 0;
    for (char c : s) {
        arr[c - 'A'] = i;
        i++;
    }
    int total = 0;
    int cur = arr[0];
    for (char c = 'B'; c <= 'Z'; c++) {
        total += abs(arr[c - 'A'] - cur);
        cur = arr[c - 'A'];
    }
    cout << total;
}