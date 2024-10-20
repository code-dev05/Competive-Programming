#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int trap(vector<int> &height)
{
    stack<int> st;
    vector<int> result(height.size(), -1);
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[i] >= height[st.top()])
        {
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    int i = 0;
    int j;
    int n = height.size();
    int area = 0;
    while (i < n)
    {
        if (height[i] == 0)
            i++;
        while (i < n && result[i] == -1)
            i++;
        if (i < n)
        {
            j = result[i];
            area += min(height[i], height[j]) * (j - i - 1);
            int x = i + 1;
            while (x < j)
            {
                area -= height[x];
                x++;
            }
            i = j;
        }
    }
    return area;
}
int main()
{
    vector<int> height = {4, 2, 3};
    cout << trap(height);
}