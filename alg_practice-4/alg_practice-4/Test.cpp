#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<string>

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        str.push("");
        int i = 0;
        while (i < s.size())
        {
            if (s[i] > '0' && s[i] < '9')
            {
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i++] - '0');
                }
                nums.push(num);
            }

            else if (s[i] == '[')
            {
                i++;
                string tmp;
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    tmp += s[i++];
                }
                str.push(tmp);
            }

            else if (s[i] == ']')
            {
                int n = nums.top();
                nums.pop();
                string tmp = str.top();
                str.pop();

                while (n--)
                {
                    str.top() += tmp;
                }
                i++;
            }

            else
            {
                while (i < s.size() && s[i] >= 'a' && s[i] <= 'z')
                {
                    str.top() += s[i++];
                }
            }
        }

        return str.top();
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret;

        int m = num1.size(), n = num2.size();
        vector<int> v(m + n - 1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int t = 0;
        int cur = 0;
        while (cur < m + n - 1 || t != 0)
        {
            if (cur < m + n - 1)
                t += v[cur++];
            ret += to_string(t % 10);
            t /= 10;
        }
        while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n + 1);
        vector<int> back(n + 1);
        front[0] = back[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            front[i] = front[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            back[i] = back[i + 1] * nums[i + 1];
        }

        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = front[i] * back[i];
        }

        return ret;

    }
};