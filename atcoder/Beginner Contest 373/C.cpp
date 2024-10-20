#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = INT_MIN;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a = max(a, temp);
    }
    int b = INT_MIN;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b = max(b, temp);
    }
    cout << a + b;
}