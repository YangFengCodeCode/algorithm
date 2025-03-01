#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        return nums[left] == target ? left : -1;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1, -1 };
        int left = 0, right = nums.size() - 1;
        //ÕÒ×ó¶Ëµã
        int a, b;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        a = nums[left] == target ? left : -1;

        //ÓÒ¶Ëµã
        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        b = nums[right] == target ? right : -1;

        return { a, b };
    }
};



class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x;
        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }

        return left;
    }
};



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        return nums[left] == target ? left : left + 1;
    }
};


class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (records[mid] == mid) left = mid;
            else right = mid - 1;
        }
        return records[right] == right ? right + 1 : right;
    }
};