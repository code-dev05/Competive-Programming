#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    set<pii> st;
    vector<vector<pii>> arr(2001, vector<pii>(2001, {-2002, -2002}));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[a + 1000][b + 1000] = {c + 1000, d + 1000};
        arr[c + 1000][d + 1000] = {a + 1000, b + 1000};
    }
    
}