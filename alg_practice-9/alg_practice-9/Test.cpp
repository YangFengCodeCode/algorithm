#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> hash1;
        for (auto str : words)
        {
            hash1[str]++;
        }

        int n = words.size(), len = words[0].size();
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash2[in] <= hash1[in]) count++;
                if (right - left + 1 > n * len)
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out]-- <= hash1[out]) count--;
                    left += len;
                }
                if (count == n) ret.push_back(left);
            }
        }

        return ret;
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        int kinds = 0;
        unordered_map<char, int> hash1;
        for (char c : t)
        {
            if (hash1[c]++ == 0) kinds++;
        }

        unordered_map<char, int> hash2;
        int begin = -1, len = INT_MAX;
        string ret;
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash2[in] == hash1[in]) count++;
            while (count == kinds)
            {
                if (right - left + 1 < len)
                {
                    begin = left;
                    len = right - left + 1;
                }

                char out = s[left];
                if (hash2[out]-- == hash1[out]) count--;
                left++;
            }
        }

        if (begin == -1) return "";
        else return s.substr(begin, len);
    }
};


#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return string字符串vector
     */
    vector<string> ret;

    void dfs(int n, string A, string B, string C)
    {
        if (n == 0)
        {
            return;
        }
        dfs(n - 1, A, C, B);
        ret.push_back("move from " + A + " to " + C);

        dfs(n - 1, B, A, C);
    }
    vector<string> getSolution(int n) {
        // write code here
        dfs(n, "left", "mid", "right");
        return ret;
    }
};




typedef long long ll;
const ll mod = 1e9 + 7;

ll dp[10000005][2];
int n;
int main() {
    cin >> n;

    dp[1][0] = 1; dp[2][0] = 5;
    dp[1][1] = 2; dp[2][1] = 7;

    for (int i = 3; i <= n; ++i) {
        dp[i][0] = (1 + dp[i - 1][1] * 2) % mod;
        dp[i][1] = (2 + dp[i - 1][1] * 2 + dp[i - 1][0]) % mod;
    }
    cout << dp[n][0] << ' ' << dp[n][1] << endl;
    return 0;

}

