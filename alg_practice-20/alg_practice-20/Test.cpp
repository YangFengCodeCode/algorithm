#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

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
            int f = q.front();
            q.pop();
            for (int i : hash[f])
            {
                in[i]--;
                if (in[i] == 0) q.push(i);
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (in[i]) return false;
        }
        return true;
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
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
            ret.push_back(t);
            q.pop();
            for (int e : hash[t])
            {
                in[e]--;
                if (in[e] == 0) q.push(e);
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (in[i]) return {};
        }
        return ret;
    }
};



class Solution {
public:
    unordered_map<char, unordered_set<char>> hash;
    unordered_map<char, int> in;
    bool check;
    string alienOrder(vector<string>& words) {
        for (auto& e : words)
        {
            for (int i = 0; i < e.size(); i++)
            {
                in[e[i]] = 0;
            }
        }

        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                add(words[i], words[j]);
                if (check == true) return "";
            }
        }

        queue<char> q;
        for (auto& [a, b] : in)
        {
            if (b == 0) q.push(a);
        }

        string ret;
        while (q.size())
        {
            char ch = q.front();
            ret += ch;
            q.pop();
            for (auto e : hash[ch])
            {
                in[e]--;
                if (in[e] == 0) q.push(e);
            }
        }

        for (auto& [a, b] : in)
        {
            if (b) return "";
        }

        return ret;
    }

    void add(string& s1, string& s2)
    {
        int n = min(s1.size(), s2.size());
        int i = 0;
        for (; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                char a = s1[i];
                char b = s2[i];
                if (!hash.count(a) || !hash[a].count(b))
                {
                    hash[a].insert(b);
                    in[b]++;
                }
                break;
            }
        }
        if (i == s2.size() && i < s1.size()) check = true;
    }
};