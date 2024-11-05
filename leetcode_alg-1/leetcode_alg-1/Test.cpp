#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        int ret = 0;
        for (auto x : nums)
            hash.insert(x);
        for (auto x : hash)
        {
            int cur = x;
            int len = 1;
            if (!hash.count(x - 1))
            {
                cur++;
                while (hash.count(cur))
                {
                    len++;
                    cur++;
                }
            }

            ret = max(ret, len);
        }

        return ret;
    }
};



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
        {
            if (nums[cur])
            {
                swap(nums[++dest], nums[cur]);
            }
        }

    }
};


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ret = 0;
        while (left < right)
        {
            int v = min(height[left], height[right]) * (right - left);
            ret = max(ret, v);
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return ret;

    }
};



#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < n;)
        {
            if (nums[i] > 0) break;
            int left = i + 1, right = n - 1, target = 0 - nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] > target) right--;
                else if (nums[left] + nums[right] < target) left++;
                else
                {
                    ret.push_back({ nums[i], nums[left++], nums[right--] });
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }

            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }

        return ret;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), left = 0, right = n - 1, ret = 0;
        int leftMax = 0, rightMax = 0;
        while (left < right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right])
            {
                ret += (leftMax - height[left++]);
            }

            else
            {
                ret += (rightMax - height[right--]);
            }
        }

        return ret;
    }
};