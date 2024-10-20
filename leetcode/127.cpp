#include <bits/stdc++.h>
using namespace std;

void printTable(vector<vector<int>> table) {
    for (auto i : table) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int lcs(string X, string Y) {
    vector<vector<int>> table(X.length() + 1, vector<int>(Y.length() + 1, 0));
    for (int i = 1; i <= X.length(); i++) {
        for (int j = 1; j <= Y.length(); j++) {
            if (X[i-1] == Y[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[X.length()][Y.length()];
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int count = 1;
    string cur = beginWord;
    string next;
    int i = 0;
    vector<bool> visited(wordList.size(), false);
    int flag = 0;
    for (int x = 0; x < wordList.size(); x++) {
        if (wordList[x] == endWord) flag = 1;
        if (wordList[x] == beginWord) visited[x] = true;
    }
    if (flag == 0) return 0;
    while (i < wordList.size())
    {
        for (int x = 0; x < wordList.size(); x++)
        {
            string word = wordList[x];
            int endLen = lcs(cur, endWord);
            int len = lcs(cur, word);
            cout << cur << " " << word << " " << len << endl;
            if (endLen == cur.length() - 1) return count+1;
            if (len == cur.length() - 1 && !visited[x])
            {
                visited[x] = true;
                next = word;
                count++;
                break;
            }
        }
        cur = next;
        i++;
    }
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    cout << ladderLength(beginWord, endWord, wordList);
}