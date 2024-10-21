#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]] = i;
        }

        int ret = 0;

        for (int j = 2; j < n; j++)
        {
            for (int i = 1; i < j; i++)
            {
                int a = arr[j] - arr[i];
                if (a < arr[i] && hash.count(a))
                {
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                ret = max(ret, dp[i][j]);
            }

        }

        return ret < 3 ? 0 : ret;

    }
};



class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]] = i;
        }

        int ret = 2;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int j = 2; j < n; j++)
        {
            for (int i = 1; i < j; i++)
            {
                int a = 2 * nums[i] - nums[j];
                if (hash.count(a) && hash[a] < i)
                {
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};





class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int ret = 2;
        hash[nums[0]] = 0;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = 2 * nums[i] - nums[j];
                if (hash.count(a))
                {
                    dp[i][j] = dp[hash[a]][i] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
            hash[nums[i]] = i;
        }

        return ret;
    }
};




class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<int>> hash;
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]].push_back(i);
        }

        vector<vector<int>> dp(n, vector<int>(n));
        int sum = 0;

        for (int j = 2; j < n; j++)
        {
            for (int i = 1; i < j; i++)
            {
                long long a = (long long)2 * nums[i] - nums[j];
                if (hash.count(a))
                {
                    for (auto k : hash[a])
                    {
                        if (k < i)
                            dp[i][j] += (dp[k][i] + 1);
                        else
                            break;
                    }
                }

                sum += dp[i][j];
            }
        }

        return sum;

    }
};