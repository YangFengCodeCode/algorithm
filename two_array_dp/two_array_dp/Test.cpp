#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];

    }
};



class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];

    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        for (int i = 0; i <= n; i++) dp[0][i] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i][j - 1];
                if (s[j - 1] == t[i - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];

    }
};



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else break;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }

                else
                {
                    dp[i][j] = (p[j - 1] == '?' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];

    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        s = ' ' + s, p = ' ' + p;

        dp[0][0] = true;
        for (int j = 2; j <= n; j += 2)
        {
            if (p[j] == '*') dp[0][j] = true;
            else break;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j] == '*')
                    if (p[j - 1] == '.') dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    else dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && p[j - 1] == s[i]);
                else
                    dp[i][j] = (p[j] == s[i] || p[j] == '.') && dp[i - 1][j - 1];
            }
        }

        return dp[m][n];

    }
};




class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        s1 = '-' + s1, s2 = '-' + s2, s3 = '-' + s3;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++)
        {
            if (s2[j] == s3[j]) dp[0][j] = true;
            else break;
        }

        for (int j = 1; j <= m; j++)
        {
            if (s1[j] == s3[j]) dp[j][0] = true;
            else break;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j])
                    || (s2[j] == s3[i + j] && dp[i][j - 1]);

                //if(s1[i] == s3[i+j]) dp[i][j] = dp[i-1][j];
                //else if(s2[j] == s3[i+j]) dp[i][j] = dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
            }
        }

        int sum = 0;
        for (auto s : s1) sum += s;
        for (auto s : s2) sum += s;

        return sum - dp[m][n] - dp[m][n];

    }
};



class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int ret = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ret = max(ret, dp[i][j]);
            }
        }

        return ret;

    }
};