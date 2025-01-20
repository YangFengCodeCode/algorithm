#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
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
            ret.push_back(path);
        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
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

    void dfs(vector<int>& nums, int i)
    {
        if (i == nums.size())
        {
            ret.push_back(path);
            return;
        }

        ret.push_back(path);
        for (int pos = i; pos < nums.size(); pos++)
        {
            path.push_back(nums[pos]);
            dfs(nums, pos + 1);
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> ret;
    string path;
    vector<string> numToStr = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ret;
        dfs(digits, 0);
        return ret;
    }

    void dfs(string& digits, int pos)
    {
        if (pos == digits.size())
        {
            ret.push_back(path);
            return;
        }
        int num = digits[pos] - '0';
        string s = numToStr[num];
        for (int i = 0; i < s.size(); i++)
        {
            path += s[i];
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    int aim;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, int pos, int sum)
    {
        if (sum >= aim)
        {
            if (sum == aim) ret.push_back(path);
            return;
        }

        if (pos == candidates.size()) return;
        for (int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i]);
            path.pop_back();
        }
    }


};


class Solution {
    int right = 0, left = 0, N;
    vector<string> ret;
    string path;
public:
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