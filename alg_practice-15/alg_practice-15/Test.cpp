#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    cout << dp[n];
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    cout << dp[n];
    return 0;
}
// 64 位输出请用 printf("%lld")



#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> path[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + path[i - 1][j - 1];
        }
    }

    cout << dp[n][m];
    return 0;

}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 1; i < n; i++)
    {
        int m = 0, k = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] >= v[i])
            {
                m = max(m, dp1[j]);
            }

            else {
                k = max(k, dp2[j]);
            }
        }

        dp1[i] = m + 1;
        dp2[i] = k + 1;
    }

    int ret1 = 1, ret2 = 1;
    for (int i = 0; i < n; i++)
    {
        ret1 = max(ret1, dp1[i]);
        ret2 = max(ret2, dp2[i]);
    }

    cout << ret1 << endl;
    cout << ret2 << endl;

    return 0;
}
