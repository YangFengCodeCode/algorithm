#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> dp(n + 1);
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }

    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")




#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n + 1, vector<long long>(m + 1));
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        auto g = f;

        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            g[j] = g[j + 1] + nums[j + 1];
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
        vector<long long> f(n);
        auto g = f;
        f[0] = g[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            g[j] = g[j + 1] * nums[j + 1];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(f[i] * g[i]);
        }

        return ans;
    }
};

#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int ret = 0;
        int sum = 0;
        hash[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }

        return ret;
    }
};


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ret = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
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