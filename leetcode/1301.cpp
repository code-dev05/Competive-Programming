#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int x, y;
    string path;
    int sum;
};

vector<int> dfs(vector<vector<char>> &board)
{
    int n = board.size();
    stack<Node> s;
    int max_sum = 0;
    int freq = 0;
    s.push({0, 0, "E", 0});
    while (!s.empty())
    {
        Node obj = s.top();
        s.pop();
        int i = obj.x;
        int j = obj.y;
        int digit = 0;
        if (board[i][j] != 'E' && board[i][j] != 'S' && board[i][j] != 'X')
        {
            digit = board[i][j] - '0';
        }
        string path = obj.path;

        if (i == n - 2 && j == n - 2)
        {
            if (obj.sum > max_sum)
            {
                max_sum = obj.sum;
                freq = 1;
            }
            else if (obj.sum == max_sum)
            {
                freq++;
            }
            continue;
        }

        if (i < n && j + 1 < n && board[i][j + 1] != 'X')
        {
            s.push({i, j + 1, path + board[i][j + 1], obj.sum + digit});
        }
        if (i + 1 < n && j < n && board[i + 1][j] != 'X')
        {
            s.push({i + 1, j, path + board[i + 1][j], obj.sum + digit});
        }
        if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] != 'X')
        {
            s.push({i + 1, j + 1, path + board[i + 1][j + 1], obj.sum + digit});
        }
    }
    return {max_sum, freq};
}

vector<int> pathsWithMaxScore(vector<string> &board)
{
    int n = board.size();
    vector<vector<char>> augmented_board(n + 1, vector<char>(n + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == n || j == n)
            {
                augmented_board[i][j] = '0';
            }
            else
            {
                augmented_board[i][j] = board[i][j];
            }
        }
    }
    return dfs(augmented_board);
}

void printTable(vector<string> board)
{
    for (string i : board)
    {
        for (char j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<string> board = {"E713399729", "X151558988", "5545833573", "4366595255", "23493768X9", "8X24154768", "1357922244", "8921993297", "8699512769", "214631X17S"};
    printTable(board);
    for (int i : pathsWithMaxScore(board)) {
        cout << i << " ";
    }
}
