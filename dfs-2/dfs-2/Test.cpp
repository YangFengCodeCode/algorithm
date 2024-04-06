using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

class Solution {
    int ret = 0;
    int path = 0;
public:
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (pos == nums.size()) return;

        for (int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            ret += path;
            dfs(nums, i + 1);
            path ^= nums[i];
        }
    }
};





class Solution2 {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[10];
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (pos == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            //¼ôÖ¦
            if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
                continue;
            path.push_back(nums[i]);
            check[i] = true;
            dfs(nums, pos + 1);
            //»ØËÝ
            path.pop_back();
            check[i] = false;
        }
    }
};

#include<string.h>

int main()
{
    string  s("012");
    int ret = s[1] - '0';
    cout << ret << endl;
    return 0;
}





class Solution {
    string _numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> ret;
    string path;
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return ret;
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
        for (int i = 0; i < _numToStr[num].size(); i++)
        {
            string s = _numToStr[num];
            path += s[i];
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};




class Solution {
    int left = 0, right = 0, N;
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



class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int count, N;
public:
    vector<vector<int>> combine(int n, int k) {
        count = k;
        N = n;
        dfs(1);
        return ret;
    }

    void dfs(int pos)
    {
        if (path.size() == count)
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



class Solution {
    int ret = 0;
    int t;
    int sum = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if (pos == nums.size())
        {
            if (sum == t) ret++;
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
    int ret = 0;
    int t;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        dfs(nums, 0, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos, int sum)
    {
        if (pos == nums.size())
        {
            if (sum == t) ret++;
            return;
        }


        dfs(nums, pos + 1, sum + nums[pos]);

        dfs(nums, pos + 1, sum - nums[pos]);
    }
};