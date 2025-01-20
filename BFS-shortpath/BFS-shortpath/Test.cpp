using namespace std;
#include<iostream>
#include<vector>
#include<queue>

class Solution {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[101][101];
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({ e[0], e[1] });
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
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.')
                    {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return step;
                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }

        return -1;

    }
};


#include<map>
#include<unordered_set>


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> hash(bank.begin(), bank.end());
        unordered_set<string> vis;
        string change = "ACGT";

        if (hash.count(endGene) == 0) return -1;
        if (startGene == endGene) return 0;

        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);

        int ret = 0;
        while (q.size())
        {
            ret++;
            int sz = q.size();
            while (sz--)
            {
                string t = q.front();
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    string tmp = t;
                    for (int j = 0; j < 4; j++)
                    {
                        tmp[i] = change[j];
                        if (!vis.count(tmp) && hash.count(tmp))
                        {
                            if (tmp == endGene) return ret;
                            vis.insert(tmp);
                            q.push(tmp);
                        }

                    }
                }
            }
        }

        return -1;

    }
};





class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        if (hash.count(endWord) == 0) return 0;

        int ret = 0;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        while (q.size())
        {
            ret++;
            int sz = q.size();
            while (sz--)
            {
                string t = q.front();
                q.pop();
                for (int i = 0; i < beginWord.size(); i++)
                {
                    string tmp = t;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        tmp[i] = c;
                        if (!vis.count(tmp) && hash.count(tmp))
                        {
                            if (tmp == endWord) return ret + 1;
                            vis.insert(tmp);
                            q.push(tmp);
                        }
                    }
                }

            }
        }

        return 0;


    }
};



class Solution
{
    int m, n;
public:
    int cutOffTree(vector<vector<int>>& f)
    {
        m = f.size(), n = f[0].size();
        // 1. 准备⼯作：找出砍树的顺序
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (f[i][j] > 1) trees.push_back({ i, j });

        sort(trees.begin(), trees.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2)
            {
                return f[p1.first][p1.second] < f[p2.first][p2.second];
            });
        // 2. 按照顺序砍树
        int bx = 0, by = 0;
        int ret = 0;
        for (auto& [a, b] : trees)
        {
            int step = bfs(f, bx, by, a, b);
            if (step == -1) return -1;
            ret += step;
            bx = a, by = b;
        }
        return ret;
    }
    bool vis[51][51];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int bfs(vector<vector<int>>& f, int bx, int by, int ex, int ey)
    {
        if (bx == ex && by == ey) return 0;
        queue<pair<int, int>> q;
        memset(vis, 0, sizeof vis); // 清空之前的数据
        q.push({ bx, by });
        vis[bx][by] = true;
        int step = 0;
        while (q.size())
        {
            step++;
            int sz = q.size();
            while (sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && f[x][y] && !vis[x][y])
                    {
                        if (x == ex && y == ey) return step;
                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};