using namespace std;
#include<iostream>
#include<vector>
#include<queue>

class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // ==-1 表示没有搜索过
        // != -1 表示搜索过了
        vector<vector<int>> tmp(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({ i, j });
                    tmp[i][j] = 0;
                }
            }
        }

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && tmp[x][y] == -1)
                {
                    q.push({ x,y });
                    tmp[x][y] = tmp[a][b] + 1;
                }
            }
        }

        return tmp;

    }
};












class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[501][501];
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1) vis[i][0] = true, q.push({ i, 0 });
            if (grid[i][n - 1] == 1) vis[i][n - 1] = true, q.push({ i, n - 1 });
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1) vis[0][j] = true, q.push({ 0, j });
            if (grid[m - 1][j] == 1) vis[m - 1][j] = true, q.push({ m - 1, j });
        }

        while (q.size())
        {
            auto [a, b] = q.front();
            vis[a][b] = true;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
                {
                    q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    ret++;
                }
            }
        }

        return ret;

    }
};





class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> dest(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    q.push({ i, j });
                    dest[i][j] = 0;
                }
            }
        }

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && dest[x][y] == -1)
                {
                    dest[x][y] = dest[a][b] + 1;
                    q.push({ x, y });
                }
            }
        }

        return dest;

    }
};





class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dest(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({ i, j });
                    dest[i][j] = 0;
                }
            }
        }

        int ret = -1;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && dest[x][y] == -1)
                {
                    dest[x][y] = dest[a][b] + 1;
                    ret = max(ret, dest[x][y]);
                    q.push({ x, y });
                }
            }

        }

        return ret;

    }
};