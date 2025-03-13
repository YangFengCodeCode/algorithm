#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> height(1001);
vector<int> dp1(1001, 1);
vector<int> dp2(1001, 1);

void getup(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (height[i] > height[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
}

void getdown(int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (height[i] > height[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    getup(n);
    getdown(n);

    int maxUpDown = 1;
    for (int i = 0; i < n; i++)
    {
        maxUpDown = max(maxUpDown, dp1[i] + dp2[i] - 1);
    }

    int res = n - maxUpDown;
    cout << res;
    return 0;

}
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> path(m, vector<int>(n));
    vector<pair<int, pair<int, int>>> hash;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> path[i][j];
            hash.push_back(make_pair(path[i][j], make_pair(i, j)));
        }
    }

    sort(hash.begin(), hash.end());
    vector<vector<int>> dp(m, vector<int>(n));

    while (hash.size())
    {
        pair<int, pair<int, int>> current_point = hash.back();
        hash.pop_back();
        int point = current_point.first;
        int x = current_point.second.first;
        int y = current_point.second.second;
        int mx = 1;
        if (x - 1 >= 0 && x - 1 < m)
        {
            if (path[x][y] < path[x - 1][y]) mx = max(dp[x - 1][y] + 1, mx);
        }

        if (x + 1 >= 0 && x + 1 < m)
        {
            if (path[x][y] < path[x + 1][y]) mx = max(dp[x + 1][y] + 1, mx);
        }

        if (y - 1 >= 0 && y - 1 < n)
        {
            if (path[x][y] < path[x][y - 1]) mx = max(dp[x][y - 1] + 1, mx);
        }

        if (y + 1 >= 0 && y + 1 < n)
        {
            if (path[x][y] < path[x][y + 1]) mx = max(dp[x][y + 1] + 1, mx);
        }

        dp[x][y] = max(dp[x][y], mx);

    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}
// 64 位输出请用 printf("%lld")