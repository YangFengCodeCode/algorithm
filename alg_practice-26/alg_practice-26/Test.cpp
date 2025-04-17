#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
int main() {
    int n, V;
    cin >> n >> V;
    int v[N], w[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    int dp[N][N] = { 0 };
    //int dp[n+1][V+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    cout << dp[n][V] << endl;

    memset(dp, 0, sizeof dp);

    for (int j = 1; j <= V; j++)
    {
        dp[0][j] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0 && dp[i - 1][j - v[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
    return 0;

}


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto e : nums)
        {
            sum += e;
        }
        if (sum % 2 != 0) return false;
        int aim = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(aim + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= aim; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][aim];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto e : nums)
        {
            sum += e;
        }
        int aim = (sum + target) / 2;
        if (aim < 0 || (sum + target) % 2) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(aim + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= aim; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][aim];
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (auto e : stones) sum += e;
        int aim = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(aim + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= aim; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - stones[i - 1] >= 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return sum - 2 * dp[n][aim];
    }
};



#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int main() {
    int n, V;
    cin >> n >> V;
    int v[N], w[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    int dp[N][N] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    cout << dp[n][V] << endl;
    memset(dp, 0, sizeof(dp));

    for (int j = 1; j <= V; j++)
    {
        dp[0][j] = -1;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0 && dp[i][j - v[i]] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
    return 0;





}




class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<double>> dp(n + 1, vector<double>(amount + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0)
                {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};
