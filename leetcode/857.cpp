#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double branchAndBound(vector<int> &quality, vector<int> &wage, int k, int level, double cur, double best)
{
    cout << "Number: " << cur << endl;
    if (level >= quality.size()) {
        return cur;
    }


    double branch1 = branchAndBound(quality, wage, k, level + 1, cur + quality[level], best);
    double branch2 = branchAndBound(quality, wage, k, level + 1, cur, best);
    return min(branch1, branch2);
}

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
{
    return branchAndBound(quality, wage, k, 0, 0, INT_MAX);
}

int main()
{
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    cout << mincostToHireWorkers(quality, wage, k);
}