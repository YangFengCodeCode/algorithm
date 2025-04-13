#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int aim;
    int sum = 0;
    int n;
    int ret = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), aim = target;
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (pos == n)
        {
            if (sum == aim) ret++;
            return;
        }

        sum += nums[pos];
        dfs(nums, pos + 1);
        sum -= nums[pos];

        sum -= nums[pos];
        dfs(nums, pos + 1);
        sum += nums[pos];
    }
};


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    int aim;
    int n;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size(), aim = target;
        dfs(candidates, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, int pos)
    {
        if (sum == aim)
        {
            ret.push_back(path);
            return;
        }

        if (sum > aim) return;

        for (int i = pos; i < n; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> ret;
    string path;
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }

    void dfs(string& s, int pos)
    {
        if (path.size() == s.size())
        {
            ret.push_back(path);
            return;
        }

        char c;
        //change
        if (s[pos] < '0' || s[pos] > '9')
        {
            if (isupper(s[pos]))
            {
                c = tolower(s[pos]);
            }

            else if (islower(s[pos]))
            {
                c = toupper(s[pos]);
            }

            path += c;
            dfs(s, pos + 1);
            path.pop_back();
        }

        //not change
        path += s[pos];
        dfs(s, pos + 1);
        path.pop_back();
    }
};


class Solution {
public:
    bool check[16];
    int ret = 0;
    int countArrangement(int n) {
        dfs(n, 1);
        return ret;
    }

    void dfs(int n, int pos)
    {
        if (pos == n + 1)
        {
            ret++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i] && (i % pos == 0 || pos % i == 0))
            {
                check[i] = true;
                dfs(n, pos + 1);
                check[i] = false;
            }
        }
    }
};


class Solution {
public:
    vector<vector<string>> ret;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++)
        {
            path.push_back(string(n, '.'));
        }
        dfs(n, 0);
        return ret;
    }

    void dfs(int n, int pos)
    {
        if (pos == n)
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (check(pos, i, n))
            {
                path[pos][i] = 'Q';
                dfs(n, pos + 1);
                path[pos][i] = '.';

            }

        }
    }

    bool check(int row, int col, int n)
    {
        for (int i = row; i >= 0; i--)
        {
            if (path[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (path[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (path[i][j] == 'Q')
                return false;
        }

        return true;
    }
};