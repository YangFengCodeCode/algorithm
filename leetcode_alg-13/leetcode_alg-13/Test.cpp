#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return  dp[n];
    }
};


class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);//Íµ
        auto g = f;//²»Íµ
        f[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[n - 1], g[n - 1]);
    }
};


class Solution {
public:
    int numSquares(int n) {
        int k = sqrt(n);
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        const int INF = 0x3f3f3f;
        for (int j = 1; j <= n; j++) dp[0][j] = INF;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - i * i >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
            }
        }

        return dp[k][n];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        const int INF = 0x3f3f3f;
        for (int j = 1; j <= amount; j++) dp[0][j] = INF;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }

        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (auto& s : wordDict)
            hash.insert(s);
        int n = s.size();
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        f[0] = g[0] = 1;
        int fmax = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int num = nums[i - 1];
            f[i] = max(num, max(f[i - 1] * num, g[i - 1] * num));
            g[i] = min(num, min(f[i - 1] * num, g[i - 1] * num));
            fmax = max(fmax, f[i]);
        }

        return fmax;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum % 2 != 0) return false;
        int aim = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(aim + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= aim; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][aim];

    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        int ret = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = 2;
                    if (i - 2 >= 0)
                        dp[i] = dp[i] + dp[i - 2];
                }

                else if (dp[i - 1] > 0)
                {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0)
                        {
                            dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                        }
                    }
                }

                ret = max(ret, dp[i]);
            }
        }

        return ret;
    }
};