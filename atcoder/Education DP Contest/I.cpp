#include <bits/stdc++.h>
using namespace std;

double res = 0;
void solve(vector<double>& arr, int n, int i = 0, double prob = 1, int tails = 0)  {
    if (tails > n / 2) return;
    if (i == n) {
        res += prob;
        return;
    }
    solve(arr, n, i+1, prob*arr[i], tails);
    solve(arr, n, i+1, prob*(1 - arr[i]), tails+1);
}

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(arr, n);
    cout << res;
}