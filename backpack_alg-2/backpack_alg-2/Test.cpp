#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string.h>
using namespace std;

//const int N = 1010;
//int v[N], w[N], n, V;
//int dp[N][N];
//
//int main() {
//    cin >> n >> V;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> v[i] >> w[i];
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= V; j++)
//        {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i])
//                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//
//    cout << dp[n][V] << endl;
//
//    memset(dp, 0, sizeof dp);
//    for (int j = 1; j <= V; j++) dp[0][j] = -1;
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= V; j++)
//        {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i] && dp[i][j - v[i]] != -1)
//                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//
//    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//    return 0;
//}


const int N = 1010;
int v[N], w[N], n, V;
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= V; j++) dp[j] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            if (dp[j - v[i]] != -1)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
    return 0;
}


#include<vector>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        const int INF = 0x3f3f3f;
        for (int j = 1; j <= amount; j++) dp[0][j] = INF;
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }

        return dp[n][amount] >= INF ? -1 : dp[n][amount];

    }
};



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<double>> dp(n + 1, vector<double>(amount + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }

        return dp[n][amount];
    }
};



class Solution {
public:
    int numSquares(int n) {
        int k = sqrt(n);
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        const int INF = 0x3f3f3f;
        for (int i = 1; i <= n; i++) dp[0][i] = INF;

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= i * i)
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
            }
        }

        return dp[k][n];
    }
};