#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include<vector>

class Solution {
public:
    const int MOD = 1e9 + 7;
    int waysToStep(int n) {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 4;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);

        dp[n - 1] = cost[n - 1], dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);

    }
};



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);
        dp[0] = s[0] != '0';
        if (n == 1) return dp[0];
        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
        int tmp = (s[0] - '0') * 10 + (s[1] - '0');
        if (tmp >= 10 && tmp <= 26) dp[1] += 1;

        for (int i = 2; i < n; i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
                dp[i] += dp[i - 1];
            int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
        }

        return dp[n - 1];
    }
};


class Solution
{
public:
    int numDecodings(string s)
    {
        //优化
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1; // 保证后续填表是正确的
        dp[1] = s[0] != '0';
   

        for (int i = 2; i <= n; i++)
        {
            // 处理单独编码
                if (s[i - 1] != '0') dp[i] += dp[i - 1];
            // 如果和前⾯的⼀个数联合起来编码
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};