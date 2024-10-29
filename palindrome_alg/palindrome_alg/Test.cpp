#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
                if (dp[i][j]) ret++;
            }
        }

        return ret;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        string ret;
        int tmp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }

                if (dp[i][j])
                {
                    if (j - i + 1 > tmp)
                    {
                        tmp = j - i + 1;
                        ret = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ret;

    }
};



class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        bool ret = false;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i; j < n - 1; j++)
            {
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                {
                    ret = true;
                }
            }
        }

        return ret;

    }
};



class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    isPal[i][j] = i + 1 < j ? isPal[i + 1][j - 1] : true;
                }
            }
        }

        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (isPal[0][i]) dp[i] = 0;
            else
            {
                for (int j = 1; j <= i; j++)
                {
                    if (isPal[j][i])
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};



class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j) dp[i][j] = 1;
                    else if (i + 1 == j) dp[i][j] = 2;
                    else if (i + 1 < j) dp[i][j] = dp[i + 1][j - 1] + 2;
                }

                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];

    }
};



class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j || i + 1 == j) dp[i][j] = 0;
                    else if (i + 1 < j) dp[i][j] = dp[i + 1][j - 1];
                }

                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];

    }
};