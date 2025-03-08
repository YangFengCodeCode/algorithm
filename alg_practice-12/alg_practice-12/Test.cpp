#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param number int整型
//     * @return int整型
//     */
//    int jumpFloor(int number) {
//        // write code here
//        vector<int> dp(number + 1);
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= number; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//
//        return dp[number];
//    }
//};


#include<vector>
#include<algorithm>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param triangle int整型vector<vector<>>
     * @return int整型
     */
    int minTrace(vector<vector<int> >& triangle) {
        // write code here
        int m = triangle.size();
        vector<int> dp(m);
        dp[0] = triangle[0][0];
        int r = 0;
        for (int i = 1; i < m; i++)
        {
            if (r + 1 < triangle[i].size() && r - 1 >= 0)
            {
                dp[i] = dp[i - 1] + min(triangle[i][r], min(triangle[i][r - 1], triangle[i][r + 1]))
            }

            else if (r + 1 >= triangle[i].size() && r - 1 >= 0)
            {
                dp[i] = dp[i - 1] + min(triangle[i][r], triangle[i][r - 1])
            }

            else if (r + 1 < triangle[i].size() && r - 1 < 0)
            {
                dp[i] = dp[i - 1] + min(triangle[i][r], triangle[i][r + 1])
            }

            else
            {
                dp[i] = dp[i - 1] + triangle[i][r];
            }

            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (triangle[i][j] == dp[i] - dp[i - 1])
                {
                    r = j;
                    break;
                }
            }
        }

        return dp[m - 1];
    }
};



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param triangle int整型vector<vector<>>
     * @return int整型
     */
    int minTrace(vector<vector<int> >& triangle) {
        // write code here
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        dp[0][0] = triangle[0][0];
        int ret = INT_MAX;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }

                else if (j == i)
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }

                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            ret = min(ret, dp[m - 1][i]);
        }

        return ret;
    }
};