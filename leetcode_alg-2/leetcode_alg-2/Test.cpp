#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<queue>
using namespace std;

//
//int main()
//{
//	int nums[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
//	priority_queue<pair<int, int>> q;
//	for (int i = 0; i < 3; i++) q.push(make_pair(nums[i], i));
//	cout << q.top().first << " " << q.top().second << endl;
//
//	while (!q.empty())
//	{
//		cout << q.top().first << " " << q.top().second << endl;
//		q.pop();
//	}
//
//	return 0;
//}



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();

        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) q.push(make_pair(nums[i], i));
        ret.push_back(q.top().first);

        for (int i = k; i < n; i++)
        {
            q.push(make_pair(nums[i], i));
            while (q.top().second + k <= i)
            {
                q.pop();
            }

            ret.push_back(q.top().first);

        }
        return ret;

    }
};



#include<unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash1, hash2;
        int kinds = 0;
        int minlen = INT_MAX, begin = -1;
        for (auto e : t)
        {
            if (hash1[e]++ == 0) kinds++;
        }

        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in] == hash1[in]) count++;

            while (count == kinds)
            {
                if (right - left + 1 < minlen)
                {
                    begin = left;
                    minlen = right - left + 1;
                }

                char out = s[left];
                if (hash2[out]-- == hash1[out])
                {
                    count--;
                }
                left++;
            }
        }

        if (begin == -1) return "";
        else return s.substr(begin, minlen);

    }
};

#include<algorithm>
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

#include<vector>
int main()
{
	vector<vector<int>> v = { {1,2}, {3, 1}, {2, 2} };
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		for (auto a : e)
		{
			cout << a << " ";
		}
		cout << endl;
	}
}


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (!ret.size() || ret.back()[1] < left)
            {
                ret.push_back({ left, right });
            }

            else
            {
                ret.back()[1] = max(ret.back()[1], right);
            }

        }

        return ret;

    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[(i + k) % n] = nums[i];
        }

        nums.assign(v.begin(), v.end());

    }
};



class Solution {
public:

    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> g(n), f(n);
        g[0] = f[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            g[i] = g[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            f[j] = f[j + 1] * nums[j + 1];
        }

        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = g[i] * f[i];
        }

        return ret;

    }
};