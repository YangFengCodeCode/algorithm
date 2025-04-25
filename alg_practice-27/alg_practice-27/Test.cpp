#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

        for (int i = 1; i <= len; i++)
        {
            int a = 0, b = 0;
            for (auto ch : strs[i - 1])
            {
                if (ch == '0') a++;
                else b++;
            }

            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j - a >= 0 && k - b >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - a][k - b] + 1);
                    }
                }
            }
        }

        return dp[len][m][n];
    }
};


class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        int len = group.size(), k = profit.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(m + 1)));
        const int MOD = 1e9 + 7;

        for (int j = 0; j <= n; j++) dp[0][j][0] = 1;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= m; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= group[i - 1])
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];
                    dp[i][j][k] %= MOD;
                }
            }
        }

        return dp[len][n][m];

    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto x : nums)
                if (i >= x)
                    dp[i] += dp[i - x];
        }

        return dp[target];

    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<double>> dp(n + 1, vector<double>(amount + 1));
        const int INF = 0x3f3f3f3f;
        for (int j = 1; j <= amount; j++)
        {
            dp[0][j] = INF;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0 && dp[i][j - coins[i - 1]] != INF)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }

        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};