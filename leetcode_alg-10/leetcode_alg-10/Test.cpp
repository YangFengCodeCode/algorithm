#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int m, n;
    bool vis[7][7];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = true;
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 1)) return true;
                }
                vis[i][j] = false;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int bx, int by, int pos)
    {
        if (pos == word.size()) return true;

        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && word[pos] == board[x][y])
            {
                vis[x][y] = true;
                if (dfs(board, word, x, y, pos + 1)) return true;
                vis[x][y] = false;
            }
        }
        return false;
    }
};


class Solution {
public:
    vector<vector<string>>result;
    vector<string>path;
    void backtracking(string& s, int startindex) {
        if (startindex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            if (isback(s, startindex, i)) {
                string str = s.substr(startindex, i - startindex + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isback(string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> result;

    void dfs(int n, int row, vector<string>& path)
    {
        if (row == n)
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isvalid(n, row, i, path))
            {
                path[row][i] = 'Q';
                dfs(n, row + 1, path);
                path[row][i] = '.';
            }
        }
    }

    bool isvalid(int n, int row, int col, vector<string>& path)
    {
        for (int i = 0; i < n; i++)
        {
            if (path[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (path[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (path[i][j] == 'Q')
                return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        dfs(n, 0, path);
        return result;
    }
};