#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool check[7];
    vector<vector<int>> ret;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!check[i])
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                check[i] = false;
                path.pop_back();
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        ret.push_back(path);
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};


class Solution {
public:
    int ret = 0;
    int path = 0;
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (pos == nums.size())
        {
            ret += path;
            return;
        }

        ret += path;
        for (int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            dfs(nums, i + 1);
            path ^= nums[i];
        }
    }
};

#include<algorithm>
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    bool check[10];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
            {
                continue;
            }

            check[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            check[i] = false;
        }
    }
};



class Solution {
public:
    vector<string> ret;
    string path;
    int n;
    string arr[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ret;
        n = digits.size();
        dfs(digits, 0);
        return ret;
    }

    void dfs(string digits, int pos)
    {
        if (pos == digits.size())
        {
            ret.push_back(path);
            return;
        }

        int index = digits[pos] - '0';
        for (int i = 0; i < arr[index].size(); i++)
        {
            path.push_back(arr[index][i]);
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> ret;
    string path;
    int left = 0, right = 0, N;
    vector<string> generateParenthesis(int n) {
        N = n;
        dfs();
        return ret;
    }

    void dfs()
    {
        if (right == N)
        {
            ret.push_back(path);
            return;
        }

        if (left < N)
        {
            path += "(";
            left++;
            dfs();
            left--;
            path.pop_back();
        }

        if (right < left)
        {
            path += ")";
            right++;
            dfs();
            right--;
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    int N, K;
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        dfs(1);
        return ret;
    }

    void dfs(int pos)
    {
        if (path.size() == K)
        {
            ret.push_back(path);
            return;
        }

        for (int i = pos; i <= N; i++)
        {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    }
};