#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 0;
    string s;
    for (int i = 1; i <= 12; i++) {
        cin >> s;
        if (s.size() == i) count++;
    }
    cout << count;
}