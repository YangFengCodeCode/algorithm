#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[128] = { 0 };
        int len = INT_MIN;
        for (int left = 0, right = 0; right < n; right++)
        {
            char ch = s[right];
            hash[ch]++;
            while (hash[ch] > 1)
            {
                hash[s[left++]]--;
            }
            len = max(len, right - left + 1);
        }

        return len == INT_MIN ? 0 : len;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int len = INT_MIN;
        for (int left = 0, right = 0; right < n; right++)
        {
            if (nums[right] == 0) count++;
            if (count > k)
            {
                if (nums[left++] == 0) count--;
            }
            len = max(len, right - left + 1);
        }

        return len;
    }
};

#include<unordered_map>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> hash;
        int ret = INT_MIN;
        for (int left = 0, right = 0; right < n; right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }

        return ret == INT_MIN ? 0 : ret;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[128] = { 0 }, hash2[128] = { 0 };
        for (auto ch : p)
        {
            hash1[ch]++;
        }

        int count = 0;
        vector<int> ret;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash2[in] <= hash1[in]) count++;
            if (right - left + 1 > p.size())
            {
                char out = s[left];
                if (hash2[out] <= hash1[out]) count--;
                hash2[out]--;
                left++;
            }

            if (count == p.size()) ret.push_back(left);
        }

        return ret;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> hash1;
        vector<int> ret;
        for (auto str : words)
        {
            hash1[str]++;
        }

        int n = words.size(), len = words[0].size();
        int sz = n * len;

        for (int i = 0; i < len; i++)
        {
            int count = 0;
            unordered_map<string, int> hash2;
            for (int left = i, right = i; right + len <= s.size(); right += len)
            {
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash1.count(in) && hash2[in] <= hash1[in]) count++;
                if (right - left + 1 > sz)
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out] <= hash1[out]) count--;
                    hash2[out]--;
                    left += len;
                }

                if (count == n)
                {
                    ret.push_back(left);
                }
            }
        }

        return ret;
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        int kinds = 0;
        for (char ch : t)
        {
            if (hash1[ch] == 0) kinds++;
            hash1[ch]++;
        }

        int begin = -1, len = INT_MAX;
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

                if (hash2[s[left]]-- == hash1[s[left]]) count--;
                left++;
            }
        }

        if (begin == -1) return "";
        else return s.substr(begin, len);
    }
};