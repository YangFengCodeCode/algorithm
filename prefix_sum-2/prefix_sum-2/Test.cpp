#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ret = 0;
        unordered_map<int, int> hash;
        hash[0 % k] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int r = (sum % k + k) % k;
            if (hash.count(r)) ret += hash[r];
            hash[r]++;
        }
        return ret;

    }
};




class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, ret = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
            else hash[sum] += i;
        }
        return ret;
    }
};



class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
                int x2 = min(m - 1, i + k) + 1, y2 = min(n - 1, j + k) + 1;
                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }

        return ret;

    }
};