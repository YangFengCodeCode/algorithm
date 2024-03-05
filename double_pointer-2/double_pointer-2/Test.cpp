#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ret = 0;
        while (left < right)
        {
            int v = min(height[left], height[right]) * (right - left);
            ret = max(ret, v);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ret;

    }
};



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = nums.size() - 1; i >= 2; i--)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    sum += (right - left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return sum;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        sort(price.begin(), price.end());
        int left = 0, right = price.size() - 1;
        while (left < right)
        {
            if (price[left] + price[right] < target)
            {
                left++;
            }
            else if (price[left] + price[right] > target)
            {
                right--;
            }
            else
            {
                return { price[left], price[right] };
            }
        }

        return { -1, -1 };

    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] > 0)
            {
                break;
            }
            int left = i + 1, right = nums.size() - 1, target = 0 - nums[i];

            //两数之和算法
            while (left < right)
            {
                if (nums[left] + nums[right] > target) right--;
                else if (nums[left] + nums[right] < target) left++;
                else
                {
                    ret.push_back({ nums[i], nums[left++], nums[right--] });
                    //去重1
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (right > left && nums[right] == nums[right + 1]) right--;
                }
            }

            i++;
            //去重2
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
        }

        return ret;

    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            //三数之和算法
            for (int j = i + 1; j < n;)
            {
                long long int aim = (long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                //两数之和算法
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > aim) right--;
                    else if (sum < aim) left++;
                    else
                    {
                        ret.push_back({ nums[i], nums[j], nums[left++], nums[right--] });
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }

                j++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }

            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }

        return ret;
    }
};