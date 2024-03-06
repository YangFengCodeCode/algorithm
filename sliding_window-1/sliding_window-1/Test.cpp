#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];// 进窗口
            while (sum >= target)//判断
            {
                len = min(len, right - left + 1);//更新结果
                sum -= nums[left++];//出窗口
            }
        }
        return len == INT_MAX ? 0 : len;

    }
};

//时间复杂度 O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 }, ret = 0;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;

    }
};


//枚举「从每⼀个位置」开始往后，⽆重复字符的⼦串可以到达什么位置。找出其中⻓度最⼤的即可。
//在往后寻找⽆重复⼦串能到达的位置时，可以利⽤「哈希表」统计出字符出现的频次，来判断什么时候⼦串出现了重复元素。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0; // 记录结果
        int n = s.length();
        // 1. 枚举从不同位置开始的最⻓重复⼦串
        // 枚举起始位置
        for (int i = 0; i < n; i++)
        {
            // 创建⼀个哈希表，统计频次
            int hash[128] = { 0 };

            // 寻找结束为⽌
            for (int j = i; j < n; j++)
            {
                hash[s[j]]++; // 统计字符出现的频次
                if (hash[s[j]] > 1) // 如果出现重复的
                    break;

                // 如果没有重复，就更新 ret
                ret = max(ret, j - i + 1);
            }
        }
        // 2. 返回结果
        return ret;
    }
};


/*从前往后 枚举数组中的任意⼀个元素，把它当成起始位置。然后从这个「起始位置」开始，然后寻找⼀段最短的区间，使得这段区间的和「⼤于等于」⽬标值。
将所有元素作为起始位置所得的结果中，找到「最⼩值」即可*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 记录结果
        int ret = INT_MAX;
        int n = nums.size();
        // 枚举出所有满⾜和⼤于等于 target 的⼦数组[start, end]
        // 由于是取到最⼩，因此枚举的过程中要尽量让数组的⻓度最⼩
        // 枚举开始位置
        for (int start = 0; start < n; start++)
        {
            int sum = 0; // 记录从这个位置开始的连续数组的和
            // 寻找结束位置
            for (int end = start; end < n; end++)
            {
                sum += nums[end]; // 将当前位置加上

                if (sum >= target) // 当这段区间内的和满⾜条件时
                {
                    // 更新结果，start 开头的最短区间已经找到
                    ret = min(ret, end - start + 1);
                    break;
                }
            }
        }
        // 返回最后结果
        return ret == INT_MAX ? 0 : ret;
    }
};



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, ret = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            if (nums[right] == 0) count++;
            while (count > k)
            {
                if (nums[left++] == 0) count--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;

    }
};



class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), target = 0, ret = -1;
        int sum = 0;
        for (int e : nums)
        {
            sum += e;
        }
        target = sum - x;
        if (target < 0)
        {
            return -1;
        }
        sum = 0;
        //找最长连续子数组, 且每个元素加起来的值为target
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum > target)
            {
                sum -= nums[left++];
            }
            if (sum == target)
                ret = max(ret, right - left + 1);
        }
        if (ret == -1) return ret;
        else return n - ret;
    }
};


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int ret = 0;
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                    hash.erase(fruits[left]);
                left++;
            }

            ret = max(ret, right - left + 1);
        }
        return ret;

    }
};