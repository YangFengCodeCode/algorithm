#include <iostream>
#include <sys/types.h>
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

    int ans = 0;
    int pos = n - 1;
    ans += arr[pos];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] + i >= pos)
        {
            ans += arr[i];
            pos = i;
        }
    }

    if (pos == 0) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")



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

    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    int curLen = v[0];
    int maxLen = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] + i > maxLen)
        {
            maxLen = n - 1 < v[i] + i ? n - 1 : v[i] + i;
        }

        if (i == curLen)
        {
            curLen = maxLen;
            res++;
        }
    }

    if (curLen >= n - 1) cout << res << endl;
    else cout << -1 << endl;
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
    vector<int> v(n);
    int dp = INT_MIN;
    int tmp = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < tmp) tmp = v[i];
        dp = max(dp, v[i] - tmp);
    }

    cout << (dp < 0 ? 0 : dp) << endl;
    return 0;

}
// 64 位输出请用 printf("%lld")