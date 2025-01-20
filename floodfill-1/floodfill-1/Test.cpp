using namespace std;
#include<iostream>
#include<vector>
#include<string>

class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int _color;
    int aim = 0;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        _color = color;
        aim = image[sr][sc];
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
            if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == aim)
            {
                image[x][y] = _color;
                dfs(image, x, y);
            }
        }
    }
};



class Solution {
    bool vis[301][301];
    int ret;
    int m, n;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }

        return ret;
    }

    void dfs(vector<vector<char>>& grid, int bx, int by)
    {
        if (grid[bx][by] == 0) return;

        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '0' && !vis[x][y])
            {
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }

    }
};



class Solution {
    int ret = 0, m, n;
    bool vis[51][51];
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    int count;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
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

    void dfs(vector<vector<int>>& grid, int bx, int by)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
            {
                count++;
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }

    }
};