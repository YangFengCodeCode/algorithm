#define _CRT_SECURE_NO_WARNINGS 1
#include <climits>
#include <iostream>
using namespace std;
#include<vector>
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n);
    dp[0] = v[0];
    int ret = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
        ret = max(ret, dp[i]);
    }

    cout << (ret == INT_MIN ? dp[0] : ret);
    return 0;
}
// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                m = max(m, dp[j]);
            }
        }

        dp[i] = m + 1;
    }

    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, dp[i]);
    }

    cout << ret << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")



int main() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m];
    return 0;
}
// 64 位输出请用 printf("%lld")