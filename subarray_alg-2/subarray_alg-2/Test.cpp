#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int sum = 0;

        for (int i = 2; i < n; i++)
        {
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }

        return sum;

    }
};



class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n, 1);
        auto g = f;
        int ret = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] < arr[i])
                f[i] = g[i - 1] + 1;
            else if (arr[i - 1] > arr[i])
                g[i] = f[i - 1] + 1;

            ret = max(ret, max(f[i], g[i]));
        }

        return ret;

    }
};

#include<string>
#include<unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> hash;
        for (auto& s : wordDict) hash.insert(s);

        vector<bool> dp(n + 1);
        dp[0] = true;
        s = ' ' + s;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};



class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
            {
                dp[i] += dp[i - 1];
            }

        }

        int hash[26] = { 0 };
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);
        }

        int sum = 0;
        for (auto x : hash)
        {
            sum += x;
        }

        return sum;
    }
};