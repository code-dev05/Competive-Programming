#include <bits/stdc++.h>
using namespace std;

double distance(int a, int b, int c, int d) {
    return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        ans += distance(x, y, t1, t2);
        x = t1;
        y = t2;
    }

    ans += distance(x, y, 0, 0);

    cout << fixed << setprecision(10) << ans;
}