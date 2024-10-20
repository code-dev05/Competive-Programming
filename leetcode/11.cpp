#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int area = 0;
    int n, temp;
    while (i < j) {
        n = min(height[i], height[j]);
        temp = n * (j - i);
        if (area < temp) area = temp;
        if (height[i] < height[j]) i++;
        else j--;
    }
    return area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);
}