#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > nums[mid - 1]) left = mid;
            else right = mid - 1;
        }
        return left;

    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int n = nums[right];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > n) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};




class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid) left = mid + 1;
            else right = mid;
        }
        return records[left] == left ? left + 1 : left;
    }
};