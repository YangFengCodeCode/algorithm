using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // 1. 准备工作
        unordered_map<int, vector<int>> edges;
        vector<int> in(n); //存入度

        //2 构图
        for (auto& e : prerequisites)
        {
            int a = e[0];
            int b = e[1];// b-->a
            edges[b].push_back(a);
            in[a]++;
        }

        //3 拓扑排序

        queue<int> q;
        //把所有入度为0的加入到队列中
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
                q.push(i);
        }

        while (q.size())
        {
            int t = q.front();
            q.pop();
            for (int e : edges[t])
            {
                in[e]--;
                if (in[e] == 0) q.push(e);
            }
        }

        //判断是否有环
        for (int i = 0; i < n; i++)
        {
            if (in[i]) return false;
        }

        return true;


    }
};




class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edgs;
        vector<int> in(n);

        for (auto& e : prerequisites)
        {
            int a = e[0];
            int b = e[1];// b--> a
            edgs[b].push_back(a);
            in[a]++;
        }

        queue<int> q;
        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0) q.push(i);
        }

        while (q.size())
        {
            int t = q.front();
            q.pop();
            ret.push_back(t);
            for (int e : edgs[t])
            {
                in[e]--;
                if (in[e] == 0) q.push(e);
            }
        }

        if (ret.size() == n) return ret;
        else return {};
    }
};







class Solution {
    unordered_map<char, unordered_set<char>> edges;
    unordered_map<char, int> in;
    bool check;
public:
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
            char t = q.front();
            q.pop();
            ret += t;

            for (char ch : edges[t])
            {
                if (--in[ch] == 0) q.push(ch);
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
                char a = s1[i], b = s2[i]; // a -> b
                if (!edges.count(a) || !edges[a].count(b))
                {
                    edges[a].insert(b);
                    in[b]++;
                }
                break;
            }
        }
        if (i == s2.size() && i < s1.size()) check = true;
    }
};