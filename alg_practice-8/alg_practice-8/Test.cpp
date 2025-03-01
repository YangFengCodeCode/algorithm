#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>


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
        int hash[128] = { 0 };
        int ret = INT_MIN;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            hash[s[right]]++;

            while (hash[s[right]] > 1 && left < s.size())
            {
                hash[s[left]]--;
                left++;
            }

            ret = max(ret, right - left + 1);
        }

        return ret == INT_MIN ? 0 : ret;

    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0, len = INT_MIN;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0) count++;
            while (count > k)
            {
                if (nums[left] == 0) count--;
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, ret = INT_MIN;
        for (auto e : nums)
        {
            sum += e;
        }

        if (sum < x) return -1;
        int target = sum - x;
        sum = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum > target)
            {
                sum -= nums[left++];
            }
            if (sum == target) ret = max(ret, right - left + 1);
        }

        return ret == INT_MIN ? -1 : nums.size() - ret;
    }
};


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int ret = INT_MIN;
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2 && left < fruits.size())
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0) hash.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hash1[128], hash2[128];
        for (char c : p)
        {
            hash1[c]++;
        }

        int count = 0;
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

