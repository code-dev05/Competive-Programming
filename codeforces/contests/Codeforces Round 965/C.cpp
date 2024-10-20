#include <bits/stdc++.h>

using namespace std;


#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;    
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    sort(arr.begin(), arr.end(), [](pii a, pii b{
        return a.first < b.first;
    });
    int median = (n)/2;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
