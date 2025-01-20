#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int m, n;
    bool vis[301][301];
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    int ret;
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
        for (int k = 0; k < 4; k++)
        {
            int x = bx + dx[k];
            int y = by + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y])
            {
                vis[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }
};



class Solution {
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({ i, j });
        }
        while (!q.empty()) {
            int n = q.size();
            bool rotten = false;
            for (int i = 0; i < n; i++)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int i = a + dx[k];
                    int j = b + dy[k];
                    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({ i, j });
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten) min++;
        }
        return fresh ? -1 : min;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hash;
        vector<int> in(numCourses);
        for (auto e : prerequisites)
        {
            int a = e[0], b = e[1];
            hash[b].push_back(a);
            in[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0) q.push(i);
        }

        while (q.size())
        {
            int t = q.front();
            q.pop();
            for (auto e : hash[t])
            {
                in[e]--;
                if (in[e] == 0) q.push(e);
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (in[i]) return false;
        }

        return true;

    }
};


class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie* searchPrefix(string prefix)
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }
    Trie() :children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;

    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;

    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
