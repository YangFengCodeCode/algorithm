#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

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
public:
    bool row[10][10];
    bool col[10][10];
    bool grid[10][10][10];
    int m, n;
    void solveSudoku(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    grid[i / 3][j / 3][num] = true;
                }
            }
        }

        dfs(board);
    }

    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (!row[i][k] && !col[j][k] && !grid[i / 3][j / 3][k])
                        {
                            int num = k + '0';
                            board[i][j] = num;
                            row[i][k] = col[j][k] = grid[i / 3][j / 3][k] = true;
                            if (dfs(board) == true) return true;
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
public:
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool check[7][7];
    string aim;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), aim = word;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    check[i][j] = true;
                    if (dfs(board, i, j, 1) == true) return true;
                    check[i][j] = false;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, int pos)
    {
        if (pos == aim.size()) return true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && board[x][y] == aim[pos])
            {
                check[x][y] = true;
                if (dfs(board, x, y, pos + 1) == true) return true;
                check[x][y] = false;
            }
        }

        return false;
    }
};


class Solution {
public:
    int ret = 0;
    int path = 0;
    bool check[101][101];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    check[i][j] = true;
                    path += grid[i][j];
                    dfs(grid, i, j);
                    path -= grid[i][j];
                    check[i][j] = false;
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        ret = max(ret, path);
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && grid[x][y] != 0)
            {
                path += grid[x][y];
                check[x][y] = true;
                dfs(grid, x, y);
                path -= grid[x][y];
                check[x][y] = false;
            }

        }
    }
};


class Solution {
public:
    int step = 0;
    int ret = 0;
    int count = 1;
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool check[21][21];
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int sx, sy;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    check[i][j] = true;
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] != -1) step++;
            }
        }

        dfs(grid, sx, sy);
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (grid[i][j] == 2)
        {
            if (count == step) ret++;
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && grid[x][y] != -1)
            {
                count++;
                check[x][y] = true;
                dfs(grid, x, y);
                count--;
                check[x][y] = false;
            }
        }
    }
};