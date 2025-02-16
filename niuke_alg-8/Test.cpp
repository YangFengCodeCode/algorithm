#include <iostream>
#include <vector>
#include<queue>
using namespace std;


bool vis[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
int xs, ys, xt, yt;
int bfs(int xs, int ys, vector<vector<char>>& vv)
{
    queue<pair<int, int>> q;
    q.push({ xs, ys });
    int step = 0;
    while (q.size())
    {
        step++;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto [a, b] = q.front();
            q.pop();
            vis[a][b] = true;
            for (int k = 0; k < 4; k++)
            {
                int x = dx[k] + a;
                int y = dy[k] + b;
                if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && vv[x][y] == '.')
                {
                    if (x == xt && y == yt) return step;
                    q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }
    }

    return -1;

}
int main() {
    cin >> n >> m;
    cin >> xs >> ys >> xt >> yt;
    vector<vector<char>> vv(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> vv[i][j];
        }
    }

    cout << bfs(xs, ys, vv);
    return 0;

}
// 64 λ������� printf("%lld")


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * �жϵ�������
     * @param grid char�ַ���vector<vector<>>
     * @return int����
     */
    int ret = 0;
    int m, n;
    bool vis[301][301];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    void bfs(int i, int j, vector<vector<char> >& grid)
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
                int x = dx[k] + a;
                int y = dy[k] + b;
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1')
                {
                    vis[x][y] = true;
                    q.push({ x, y });
                }
            }
        }
    }
    int solve(vector<vector<char> >& grid) {
        // write code here
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
};