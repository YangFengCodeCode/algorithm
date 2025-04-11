#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
    int prev, _color;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(), n = image[0].size();
        prev = image[sr][sc];
        _color = color;
        if (prev == color) return image;
        image[sr][sc] = color;
        dfs(image, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc)
    {
        if (image[sr][sc] == 0) return;
        for (int k = 0; k < 4; k++)
        {
            int x = sr + dx[k];
            int y = sc + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev)
            {
                image[x][y] = _color;
                dfs(image, x, y);
            }
        }
    }
};


class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
    bool vis[301][301];
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<char>>& grid, int sr, int sc)
    {
        if (grid[sr][sc] == '0') return;
        for (int k = 0; k < 4; k++)
        {
            int x = sr + dx[k];
            int y = sc + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1')
            {
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }
};


class Solution {
public:
    int m, n;
    bool vis[51][51];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int ret = 0;
    int count;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    count = 1;
                    vis[i][j] = true;
                    dfs(grid, i, j);
                    ret = max(ret, count);
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (grid[i][j] == 0) return;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
            {
                vis[x][y] = true;
                count++;
                dfs(grid, x, y);
            }
        }
    }
};


class Solution {
public:
    int m, n;
    bool vis[201][201];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board);
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

    void dfs(int a, int b, vector<vector<char>>& board)
    {
        if (board[a][b] == 'X') return;
        vis[a][b] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == 'O')
            {
                vis[x][y] = true;
                dfs(x, y, board);
            }
        }
    }
};


class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visP(m, vector<bool>(n));
        vector<vector<bool>> visA(m, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, heights, visP);
            dfs(m - 1, i, heights, visA);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, heights, visP);
            dfs(i, n - 1, heights, visA);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visA[i][j] && visP[i][j])
                {
                    ret.push_back({ i, j });
                }
            }
        }

        return ret;


    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && heights[i][j] <= heights[x][y])
            {
                dfs(x, y, heights, vis);
            }
        }
    }
};


class Solution {
public:
    int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
    int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
    int m, n;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
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
            board[i][j] = 'B';
            for (int k = 0; k < 8; k++)
            {
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