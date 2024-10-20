#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = 4;
    for (int i = 0; i < pow(2, n); i++) {
        vector<int> temp;
        for (int j = n-1; j >= 0; j++) {
            if (i >> (n - j - 1) == 1) {
                // temp.push_back()
            }
        }
    }
}