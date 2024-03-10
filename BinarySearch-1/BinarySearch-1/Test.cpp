#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<map>



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        }
        return -1;

    }
};



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1, -1 };
        //二分左端点
        int left = 0, right = nums.size() - 1, begin = 0;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] != target) return { -1, -1 };
        else begin = left;

        //二分右端点
        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        return { begin, right };
    }
};


class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        int left = 1, right = x;
        while (left < right)
        {
            long long int mid = left + (right - left + 1) / 2;
            long long m = mid * mid;
            if (m > x) right = mid - 1;
            else left = mid;
        }
        return right;
    }
};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] < target) return left + 1;
        else return left;

    }
};



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1]) left = mid;
            else right = mid - 1;
        }
        return right;

    }
};