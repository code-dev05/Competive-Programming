#include <bits/stdc++.h>
using namespace std;

int s = 0;
void solve(vector<int>& arr, int ind, int& ans, int& diff, int cur=0) {
    int n = arr.size();
    if (ind >= n) return;

    int a = cur;
    int b = s - a;
    if (max(a, b) - min(a, b) < diff) {
        ans = max(a, b);
        diff = max(a, b) - min(a, b);
    }
    solve(arr, ind+1, ans, diff, cur+arr[ind]);
    solve(arr, ind+1, ans, diff, cur);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    s = sum;
    int ans = 0;
    int diff = INT_MAX;
    solve(arr, 0, ans, diff);
    cout << ans;
}