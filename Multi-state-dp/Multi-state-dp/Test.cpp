using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> f(n);
        vector<int> g(n);

        f[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }

        return max(f[n - 1], g[n - 1]);

    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
    }

    int rob1(vector<int>& nums, int left, int right)
    {
        int n = nums.size();
        if (left > right) return 0;

        vector<int> f(n);
        auto g = f;

        f[left] = nums[left];

        for (int i = left + 1; i <= right; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[right], g[right]);
    }
};



class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 10001;
        int arr[N] = { 0 };
        for (auto e : nums)
        {
            arr[e] += e;
        }

        vector<int> f(N);
        auto g = f;

        f[0] = arr[0];
        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(f[i - 1], g[i - 1]);
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
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0] - fee);
        }

        return dp[m - 1][1];

    }
};



class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        
        int n = prices.size();
        vector<int> f(n);
        auto g = f;
        f[0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = max(f[i - 1], g[i - 1] - prices[i]);
            g[i] = max(g[i - 1], f[i - 1] + prices[i] - fee);
        }
        return g[n - 1];
    }
};



class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> f(m, vector<int>(3, -INF));
        auto g = f;
        f[0][0] = -prices[0];
        g[0][0] = 0;

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                if (j - 1 >= 0)
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
            }
        }

        return max(g[m - 1][0], max(g[m - 1][1], g[m - 1][2]));

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