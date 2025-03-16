#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
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

    cout << dp[0][n - 1];
    return 0;
}



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> f(n + 1);
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i - 1], g[i - 1]);
        g[i] = f[i - 1] + arr[i - 1];
    }

    cout << max(f[n], g[n]);
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] < i) dp[i] = -1;
        else dp[i] = max(dp[i - 1], i + nums[i]);
    }

    cout << (dp[n - 1] == -1 ? "false" : "true");
    return 0;
}
// 64 位输出请用 printf("%lld")