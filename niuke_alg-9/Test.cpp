#include <iostream>
#include <linux/limits.h>
#include <set>
using namespace std;


int a[1001] = { 0 };
int n;
int ret = 0x3f3f3f3f;

bool Primer(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }

    return true;
}
void dfs(int index, int sum, set<int>& s)
{
    if (index == n)
    {
        ret = min(ret, sum);
        return;
    }
    for (int i = 2; i <= a[index]; i++)
    {
        if (a[index] % i == 0 && Primer(i) && !s.count(i))
        {
            s.insert(i);
            dfs(index + 1, sum + i, s);
            s.erase(i);
        }
    }

}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> s;
    dfs(0, 0, s);

    if (ret == 0x3f3f3f3f) cout << -1;
    else cout << ret;
    return 0;

}
// 64 位输出请用 printf("%lld")


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0, right = nums.size() - 1;
        if (nums.empty()) return -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] == target) return left;
        else return -1;
    }
};


#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    char s1[8], s2[8];
    scanf("%s %s", s1, s2);
    int a1[1500], a2[1500];
    int b1 = 0, b2 = 0;
    for (int i = 0; i < 60 * 24; i++)
    {
        int sum = i;
        if ((s1[0] - '0' == sum / 600 || s1[0] == '?') && (s1[1] - '0' == sum / 60 % 10 || s1[1] == '?') && (s1[3] - '0' == sum % 60 / 10 || s1[3] == '?') && (s1[4] - '0' == sum % 60 % 10 || s1[4] == '?'))
        {
            a1[b1++] = i;
        }
        if ((s2[0] - '0' == sum / 600 || s2[0] == '?') && (s2[1] - '0' == sum / 60 % 10 || s2[1] == '?') && (s2[3] - '0' == sum % 60 / 10 || s2[3] == '?') && (s2[4] - '0' == sum % 60 % 10 || s2[4] == '?'))
        {
            a2[b2++] = i;
        }
    }
    int max = 0, min = 60 * 24;
    for (int i = 0; i < b1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            if (a1[i] < a2[j])
            {
                max = max > a2[j] - a1[i] ? max : a2[j] - a1[i];
                min = min < a2[j] - a1[i] ? min : a2[j] - a1[i];
            }
        }
    }
    cout << min << ' ' << max;
    return 0;
}
