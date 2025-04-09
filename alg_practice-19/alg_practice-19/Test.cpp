#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int prev = image[sr][sc];
        if (prev == color) return image;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev)
                {
                    image[x][y] = color;
                    q.push({ x, y });
                }
            }
        }

        return image;
    }
};

class Solution {
public:
    bool vis[301][301];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    bfs(grid, i, j);
                }
            }
        }
        return ret;
    }

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({ x, y });
        vis[x][y] = true;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1')
                {
                    vis[x][y] = true;
                    q.push({ x, y });
                }
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    ret = max(ret, bfs(grid, i, j));
            }
        }
        return ret;
    }

    int bfs(vector<vector<int>>& grid, int x, int y)
    {
        int count = 1;
        queue<pair<int, int>> q;
        q.push({ x, y });
        vis[x][y] = true;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
                {
                    count++;
                    vis[x][y] = true;
                    q.push({ x, y });
                }
            }
        }
        return count;
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
            if (board[i][0] == 'O') bfs(i, 0, board);
            if (board[i][n - 1] == 'O') bfs(i, n - 1, board);
        }

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') bfs(0, j, board);
            if (board[m - 1][j] == 'O') bfs(m - 1, j, board);
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

    void bfs(int x, int y, vector<vector<char>>& board)
    {
        queue<pair<int, int>> q;
        q.push({ x, y });
        vis[x][y] = true;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && board[x][y] == 'O')
                {
                    vis[x][y] = true;
                    q.push({ x, y });
                }
            }
        }

    }
};