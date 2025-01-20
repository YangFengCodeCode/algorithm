using namespace std;
#include<iostream>
#include<vector>

class Solution {
    bool vis[201][201];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }

        }

    }

    void dfs(vector<vector<char>>& board, int bx, int by)
    {
        vis[bx][by] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == 'O')
            {
                dfs(board, x, y);
            }
        }
    }
};




class Solution {
    vector<vector<int>> ret;
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> checkT(m, vector<bool>(n));
        vector<vector<bool>> checkD(m, vector<bool>(n));

        // 1. 先处理 太平洋
        for (int j = 0; j < n; j++) dfs(heights, 0, j, checkT);
        for (int i = 0; i < m; i++) dfs(heights, i, 0, checkT);
        // 2. 处理 大西洋
        for (int i = 0; i < m; i++) dfs(heights, i, n - 1, checkD);
        for (int j = 0; j < n; j++) dfs(heights, m - 1, j, checkD);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (checkD[i][j] && checkT[i][j])
                {
                    ret.push_back({ i, j });
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& check)
    {
        check[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && heights[i][j] <= heights[x][y])
            {
                dfs(heights, x, y, check);
            }
        }

    }
};



class Solution {
    int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int m, n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        dfs(board, x, y);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M')
            {
                count++;
            }
        }

        if (count)
        {
            board[i][j] = count + '0';
        }

        else
        {
            for (int k = 0; k < 8; k++)
            {
                board[i][j] = 'B';
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
                {
                    dfs(board, x, y);
                }
            }
        }
    }
};



class Solution {
    int count = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    vector<vector<bool>> vis;
    int _m, _n;
    int target;
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        vis.resize(m, vector<bool>(n));
        _m = m, _n = n;
        target = cnt;
        dfs(0, 0);
        return count;
    }

    void dfs(int i, int j)
    {
        count++;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < _m && y >= 0 && y < _n && !vis[x][y] && check(x, y) <= target)
            {
                dfs(x, y);
            }
        }
    }

    int check(int x, int y)
    {
        int sum1 = 0, sum2 = 0;
        while (x)
        {
            sum1 += x % 10;
            x /= 10;
        }

        while (y)
        {
            sum1 += y % 10;
            y /= 10;
        }

        return sum1 + sum2;
    }
};