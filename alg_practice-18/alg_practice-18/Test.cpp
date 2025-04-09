#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[101][101];
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({ entrance[0], entrance[1] });
        //vis[entrance[0]][entrance[1]] = true;
        int step = 0;
        while (q.size())
        {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [a, b] = q.front();
                vis[a][b] = true;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.')
                    {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                        {
                            return step;
                        }
                        vis[x][y] = true;
                        q.push({ x, y });
                    }
                }
            }
        }

        return -1;

    }
};



class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> hash(bank.begin(), bank.end());
        unordered_set<string> vis;
        char change[4] = { 'A', 'C', 'G', 'T' };
        if (!hash.count(endGene)) return -1;
        if (startGene == endGene) return 0;
        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        int step = 0;
        while (q.size())
        {
            int sz = q.size();
            step++;
            for (int i = 0; i < sz; i++)
            {
                string str = q.front();
                q.pop();
                for (int j = 0; j < 8; j++)
                {
                    string tmp = str;
                    for (int k = 0; k < 4; k++)
                    {
                        tmp[j] = change[k];
                        if (!vis.count(tmp) && hash.count(tmp))
                        {
                            if (tmp == endGene) return step;
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
        if (beginWord == endWord) return 0;
        if (!hash.count(endWord)) return 0;
        //if(hash.size() == 2 && hash.count(beginWord) && hash.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int step = 1;
        while (q.size())
        {
            int sz = q.size();
            step++;
            for (int i = 0; i < sz; i++)
            {
                string str = q.front();
                q.pop();
                for (int j = 0; j < beginWord.size(); j++)
                {
                    string tmp = str;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        tmp[j] = ch;
                        if (!vis.count(tmp) && hash.count(tmp))
                        {
                            if (tmp == endWord) return step;
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



class Solution {
public:
    int m, n;
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(), n = forest[0].size();
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (forest[i][j] > 1) trees.push_back({ i, j });
            }
        }

        sort(trees.begin(), trees.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return forest[p1.first][p1.second] < forest[p2.first][p2.second];
            });

        int ret = 0;
        int bx = 0, by = 0;
        for (auto [a, b] : trees)
        {
            int step = bfs(forest, a, b, bx, by);
            if (step == -1) return -1;
            ret += step;
            bx = a;
            by = b;
        }

        return ret;
    }

    bool vis[51][51];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int bfs(vector<vector<int>>& forest, int ex, int ey, int sx, int sy)
    {
        if (ex == sx && ey == sy) return 0;
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({ sx, sy });
        vis[sx][sy] = true;
        int count = 0;
        while (q.size())
        {
            int sz = q.size();
            count++;
            for (int i = 0; i < sz; i++)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && forest[x][y] != 0)
                    {
                        if (x == ex && y == ey) return count;
                        vis[x][y] = true;
                        q.push({ x, y });
                    }
                }
            }
        }

        return -1;

    }
};