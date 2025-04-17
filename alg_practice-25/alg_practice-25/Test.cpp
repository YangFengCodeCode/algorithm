#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (tmp >= 10 && tmp <= 26)
                dp[i] += dp[i - 2];
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
    int massage(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        for (int i = 1; i <= n; i++)
        {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }

        return max(f[n], g[n]);

    }
};


class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        return max(nums[0] + rob(nums, 2, n - 2), rob(nums, 1, n - 1));
    }

    int rob(vector<int>& nums, int left, int right)
    {
        if (left > right) return 0;
        vector<int> f(n);
        vector<int> g(n);
        f[left] = nums[left];
        for (int i = left; i <= right; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[right], g[right]);
    }
};


class Solution {
public:
    const int N = 10001;
    int arr[10001] = { 0 };
    int deleteAndEarn(vector<int>& nums) {
        for (auto e : nums)
        {
            arr[e] += e;
        }

        vector<int> f(N);
        vector<int> g(N);
        f[0] = arr[0];
        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }

        return max(f[N - 1], g[N - 1]);
    }
};


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m = costs.size();
        vector<vector<int>> dp(m + 1, vector<int>(3));

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }

        return min(dp[m][0], min(dp[m][1], dp[m][2]));
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(3));
        dp[0][0] = -prices[0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }

        return max(dp[m - 1][1], dp[m - 1][2]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        return dp[n - 1][1];
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int INF = 0x3f3f3f3f;
        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> f(n, vector<int>(k + 1, -INF));
        auto g = f;
        f[0][0] = -prices[0];
        g[0][0] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                if (j - 1 >= 0)
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
            }
        }

        int ret = 0;
        for (int j = 0; j <= k; j++)
        {
            ret = max(ret, g[n - 1][j]);
        }

        return ret;

    }
};