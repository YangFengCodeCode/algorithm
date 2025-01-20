#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>


class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int aim;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos, int sum)
    {
        if (sum >= aim)
        {
            if (sum == aim) ret.push_back(path);
            return;
        }
        if (pos == nums.size()) return;

        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i, sum + nums[i]);
            path.pop_back();
        }
    }
};






class Solution2 {
    vector<vector<int>> ret;
    vector<int> path;
    int aim;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos, int sum)
    {
        if (sum >= aim)
        {
            if (sum == aim) ret.push_back(path);
            return;
        }
        if (pos == nums.size()) return;

        for (int k = 0; k * nums[pos] <= aim; k++)
        {
            if (k) path.push_back(nums[pos]);
            dfs(nums, pos + 1, sum + k * nums[pos]);
        }

        for (int k = 1; k * nums[pos] <= aim; k++)
        {
            path.pop_back();
        }
    }
};



class Solution {
    vector<string> ret;
    string path;
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }

    void dfs(string s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }

        char c;

        if (s[pos] < '0' || s[pos] > '9')
        {
            //变
            if (islower(s[pos]))
            {
                c = toupper(s[pos]);
            }

            else if (isupper(s[pos]))
            {
                c = tolower(s[pos]);
            }
            path.push_back(c);
            dfs(s, pos + 1);
            path.pop_back();
        }

        //不变
        path.push_back(s[pos]);
        dfs(s, pos + 1);
        path.pop_back();
    }
};


class Solution {
    bool check[16];
    int ret = 0;
public:
    int countArrangement(int n) {
        dfs(n, 1);
        return ret;
    }

    void dfs(int n, int pos)
    {
        if (pos == n + 1)
        {
            ret++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == false && (pos % i == 0 || i % pos == 0))
            {
                check[i] = true;
                dfs(n, pos + 1);
                check[i] = false;
            }
        }
    }
};



class Solution {
    bool checkcol[10];
    bool digits1[20];
    bool digits2[20];
    vector<vector<string>> ret;
    vector<string> path;
    int _n;
public:
    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        path.resize(n);
        for (int i = 0; i < n; i++)
        {
            path[i].append(n, '.');
        }

        dfs(0);
        return ret;
    }

    void dfs(int row)
    {
        if (row == _n)
        {
            ret.push_back(path);
            return;
        }

        for (int col = 0; col < _n; col++)
        {
            if (!checkcol[col] && !digits1[row - col + _n] && !digits2[row + col])
            {
                checkcol[col] = true;
                digits1[row - col + _n] = true;
                digits2[row + col] = true;
                path[row][col] = 'Q';
                dfs(row + 1);
                checkcol[col] = false;
                digits1[row - col + _n] = false;
                digits2[row + col] = false;
                path[row][col] = '.';

            }
        }
    }
};



class Solution {
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num])
                        return false;
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }

        return true;

    }
};





class Solution {
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }

        dfs(board);
    }


    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (!row[i][k] && !col[j][k] && !grid[i / 3][j / 3][k])
                        {
                            board[i][j] = k + '0';
                            row[i][k] = col[j][k] = grid[i / 3][j / 3][k] = true;
                            if (dfs(board) == true) return true;

                            //修复现场
                            board[i][j] = '.';
                            row[i][k] = col[j][k] = grid[i / 3][j / 3][k] = false;

                        }
                    }

                    return false;
                }
            }
        }
        return true;

    }
};






class Solution {
    bool vis[7][7];
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if (dfs(board, i, j, word, 1)) return true;
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos)
    {
        if (pos == word.size()) return true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == word[pos])
            {
                vis[x][y] = true;
                if (dfs(board, x, y, word, pos + 1)) return true;
                vis[x][y] = false;
            }

        }

        return false;
    }
};


class Solution {
    int ret;
    bool vis[16][16];
    int m, n;

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    vis[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    vis[i][j] = false;
                }
            }
        }

        return ret;
    }

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { -1, 1, 0, 0 };

    void dfs(vector<vector<int>>& grid, int i, int j, int path)
    {
        ret = max(ret, path);
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != 0)
            {
                vis[x][y] = true;
                dfs(grid, x, y, path + grid[x][y]);
                vis[x][y] = false;
            }

        }
    }
};



class Solution {
    int ret;
    int step = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[21][21];
    int bx, by;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = true;
                    bx = i;
                    by = j;
                }

                if (grid[i][j] != -1) step++;
            }
        }

        dfs(grid, bx, by, 1);
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int bx, int by, int count)
    {
        if (grid[bx][by] == 2)
        {
            if (count == step)
            {
                ret++;
            }
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !vis[x][y] && grid[x][y] != -1)
            {
                vis[x][y] = true;
                dfs(grid, x, y, count + 1);
                vis[x][y] = false;
            }

        }
    }
};