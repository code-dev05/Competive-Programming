#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    if (n <= 1) return n;
    else return n * factorial(n-1);
}

int sumOfDigits(int n) {
    if (n < 10) return factorial(n);
    else {
        int res = 0;
        while (n > 0) {
            res += (n % 10);
            n /= 10;
        }
        return sumOfDigits(res);
    }
}

int main() {
    int n;
    cin >> n;
    cout << sumOfDigits(n);
}