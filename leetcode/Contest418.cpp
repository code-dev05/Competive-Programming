#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int res = gcd(nums[i], nums[j]);
                arr.push_back(res);
            }
        }
        sort(arr.begin(), arr.end());
        for (int i : arr) cout << i << " ";
        cout << endl;
        vector<int> ans;
        for (int i : queries) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};
    
    vector<int> result = solution.gcdValues(nums, queries);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
