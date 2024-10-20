#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>

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
                ret = max(ret, dp[i]);
            }
        }

        return ret;
    }
};


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1);
        int ret = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    f[i] = max(f[i], g[j] + 1);
                else if (nums[j] > nums[i])
                    g[i] = max(g[i], f[j] + 1);
                ret = max(ret, max(f[i], g[i]));
            }
        }

        return ret;

    }
};


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1), count(n, 1);
        int lenVal = 1, countVal = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (len[j] + 1 == len[i])
                    {
                        count[i] += count[j];
                    }

                    else if (len[j] + 1 > len[i])
                    {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                }
            }

            if (lenVal == len[i]) countVal += count[i];
            else if (lenVal < len[i])
            {
                lenVal = len[i];
                countVal = count[i];
            }
        }

        return countVal;

    }
};



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ret = max(ret, dp[i]);
        }

        return ret;

    }
};

#include<unordered_map>

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;
        hash[arr[0]] = 1;
        int ret = 1;

        for (int i = 1; i < n; i++)
        {
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            ret = max(ret, hash[arr[i]]);
        }

        return ret;

    }
};