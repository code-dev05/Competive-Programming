#include <bits/stdc++.h>
using namespace std;

void build(vector<long long int>& arr, vector<long long int>& seg, long long int ind, long long int l, long long int r) {
    if (l == r) {
        seg[ind] = arr[l];
        return;
    }
    long long int mid = (l + r) / 2;
    build(arr, seg, 2*ind + 1, l, mid);
    build(arr, seg, 2*ind + 2, mid+1, r);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}

long long int query(vector<long long int>& seg, long long int ind, long long int low, long long int high, long long int l, long long int r) {
    if (high < l || r < low) return INT_MAX;
    if (low >= l && high <= r) return seg[ind];
    long long int mid = (low + high) / 2;
    long long int left = query(seg, 2*ind + 1, low, mid, l, r);
    long long int right = query(seg, 2*ind + 2, mid + 1, high, l, r);
    return min(left, right);
}

int main() {
    long long int n, q;
    cin >> n >> q;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    vector<long long int> seg(4*n);
    build(arr, seg, 0, 0, n-1);
    for (long long int i = 0; i < q; i++) {
        long long int l, r;
        cin >> l >> r;
        cout << query(seg, 0, 0, n-1, l-1, r-1) << endl;
    }
}