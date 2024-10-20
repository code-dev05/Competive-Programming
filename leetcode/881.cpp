#include <bits/stdc++.h>

using namespace std;

static bool descOrder(int a, int b)
{
    return a > b;
}

int numRescueBoats(vector<int> people, int limit)
{
    sort(people.begin(), people.end(), descOrder);
    int boats = 0;
    int i = 0;
    int j = people.size() - 1;
    while (i <= j) {
        int num1 = people[i];
        if (people[j] + num1 <= limit) {
            j--;
        }
        i++;
        boats++;
    }
    return boats;
}

int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << numRescueBoats(people, limit);
}