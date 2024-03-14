#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n, q;
//    cin >> n >> q;
//    long long int arr[n + 1], dp[n + 1];
//    dp[0] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> arr[i];
//        dp[i] = dp[i - 1] + arr[i];
//    }
//    while (q--)
//    {
//        long long int l, r;
//        cin >> l >> r;
//        cout << dp[r] - dp[l - 1] << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
//
//int main() {
//    int n = 0, m = 0, q = 0;
//    cin >> n >> m >> q;
//    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
//    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> arr[i][j];
//            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + arr[i][j] - dp[i - 1][j - 1];
//        }
//    }
//
//    while (q--)
//    {
//        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//    }
//
//    return 0;
//
//}



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long> f(n), g(n);

        //前缀和
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + nums[i - 1];
        }

        //后缀和
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (f[i] == g[i])
            {
                return i;
            }
        }
        return -1;


    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = g[n - 1] = 1;

        //前缀乘积
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
        }

        //后缀乘积
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] * nums[i + 1];
        }

        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = f[i] * g[i];
        }
        return ret;
    }
};

#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto e : nums)
        {
            sum += e;
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};