#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    cout << dp[n - 1][1] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = -v[0];
    dp[0][1] = 0;
    dp[0][2] = -v[0];
    dp[0][4] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], -v[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + v[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - v[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + v[i]);
    }

    cout << dp[n - 1][3];
    return 0;
}
// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> dp(k, vector<int>(2, 0));
    for (int i = 0; i < k; i++)
    {
        dp[i][0] = -prices[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (j == 0)
            {
                dp[j][0] = max(dp[j][0], -prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
            }

            else {
                dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
            }
        }
    }

    cout << (dp[k - 1][0] > 0 ? dp[k - 1][1] : 0);
    return 0;

}
// 64 位输出请用 printf("%lld")


#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
            dp[i][j] = dp[i - 1][j] + v[i][j];
        }
    }

    int ret = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int f = 0;
            for (int k = 1; k <= n; k++)
            {
                int w = dp[j][k] - dp[i - 1][k];
                f = max(f, 0) + w;
                ret = max(ret, f);
            }
        }
    }

    cout << ret;
    return 0;
}
// 64 位输出请用 printf("%lld")