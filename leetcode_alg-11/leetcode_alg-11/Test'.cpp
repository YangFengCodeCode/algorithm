#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};


class Solution {
public:
    bool binarySearch(vector<int>& path, int target)
    {
        int left = 0, right = path.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (path[mid] < target) left = mid + 1;
            else if (path[mid] > target)right = mid - 1;
            else return true;
        }

        return path[left] == target;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& path : matrix)
        {
            if (binarySearch(path, target))
            {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1, -1 };
        int left = 0, right = nums.size() - 1, begin = 0;
        //找左端点
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] != target) return { -1, -1 };
        else begin = left;

        //找右端点
        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        return { begin, right };
    }
};



class Solution {
public:
    bool binarySearch(vector<int>& path, int target)
    {
        int left = 0, right = path.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (path[mid] < target) left = mid + 1;
            else right = mid;
        }

        return path[left] == target;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& path : matrix)
        {
            if (binarySearch(path, target))
            {
                return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums[nums.size() - 1];
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > n) left = mid + 1;
            else right = mid;
        }
        int index = left;

        left = 0, right = index - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (nums[left] == target) return left;
        else
        {
            left = index;
            right = nums.size() - 1;
        }
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



class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int t = nums[right];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > t) left = mid + 1;
            else right = mid;
        }

        return nums[left];
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int totalLength = len1 + len2;
        int midIndex = totalLength / 2;

        int i = 0, j = 0; // 双指针分别指向 nums1 和 nums2
        int current = 0, previous = 0; // 用于记录当前值和前一个值

        for (int k = 0; k <= midIndex; k++) {
            previous = current; // 保存前一个值

            if (i < len1 && (j >= len2 || nums1[i] <= nums2[j])) {
                current = nums1[i];
                i++;
            }
            else {
                current = nums2[j];
                j++;
            }
        }

        // 如果总长度是奇数，直接返回当前值；如果是偶数，返回中间两个数的平均值
        if (totalLength % 2 == 1) {
            return current;
        }
        else {
            return (previous + current) / 2.0;
        }
    }
};

