using namespace std;
#include<iostream>
#include<vector>
#include<queue>

class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    typedef pair<int, int> PII;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<PII> q;
        int m = image.size(), n = image[0].size();
        int prev = image[sr][sc];
        if (prev == color) return image;

        q.push({ sr, sc });
        while (q.size())
        {
            auto [a,b] = q.front();
            q.pop();
            image[a][b] = color;
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev)
                {
                    q.push({ x, y });
                }
            }
        }

        return image;
    }
};






class Solution {
    bool vis[301][301];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    typedef pair<int, int> PII;
    int ret = 0;
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    bfs(i, j, grid);
                }
            }
        }

        return ret;

    }

    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<PII> q;
        q.push({ i, j });
        vis[i][j] = true;

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y])
                {
                    vis[x][y] = true;
                    q.push({ x, y });
                }
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
                    bfs(i, j, grid);
                    ret = max(ret, count);
                }
            }
        }
        return ret;
    }

    void bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({ i, j });
        vis[i][j] = true;

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
    }
};




class Solution {
    bool vis[201][201];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
public:
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

    void bfs(int i, int j, vector<vector<char>>& board)
    {
        queue<pair<int, int>> q;
        q.push({ i, j });
        vis[i][j] = true;

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



int main()
{
    return 0;
}