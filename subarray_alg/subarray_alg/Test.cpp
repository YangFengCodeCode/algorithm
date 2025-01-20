using namespace std;
#include<iostream>
#include<vector>


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        int ret = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        int sum = 0;
        int fmax = INT_MIN;
        int gmin = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
            sum += nums[i - 1];
            fmax = max(fmax, f[i]);
            gmin = min(gmin, g[i]);
        }

        return gmin == sum ? fmax : max(fmax, sum - gmin);

    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        f[0] = g[0] = 1;

        int fmax = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1];
            f[i] = max(x, max(f[i - 1] * x, g[i - 1] * x));
            g[i] = min(x, min(g[i - 1] * x, f[i - 1] * x));
            fmax = max(f[i], fmax);
        }

        return fmax;

    }
};


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        int ret = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1];
            if (x > 0)
            {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
            }

            else if (x < 0)
            {
                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
                g[i] = f[i - 1] + 1;
            }

            ret = max(ret, f[i]);
        }

        return ret;

    }
};