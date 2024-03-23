#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size(), i = 0;
        while (i < right)
        {
            if (nums[i] == 0) swap(nums[++left], nums[i++]);
            else if (nums[i] == 2) swap(nums[--right], nums[i]);
            else i++;
        }
    }
};



class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int key = getRandom(nums, l, r);
        int i = l, left = l - 1, right = r + 1;
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] == key) i++;
            else swap(nums[--right], nums[i]);
        }
        qsort(nums, l, left);
        qsort(nums, right, r);

    }

    int getRandom(vector<int>& nums, int left, int right)
    {
        int r = rand();
        return nums[r % (right - left + 1) + left];

    }
};




class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return qsort(nums, 0, nums.size() - 1, k);
    }

    int qsort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r) return nums[l];
        int key = getRandom(nums, l, r);
        int left = l - 1, right = r + 1, i = l;
        //分三块
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] == key) i++;
            else swap(nums[--right], nums[i]);
        }

        //选择分块
        int c = r - right + 1, b = right - left - 1;
        if (c >= k) return qsort(nums, right, r, k);
        else if (b + c >= k) return key;
        else return qsort(nums, l, left, k - b - c);
    }

    int getRandom(vector<int>& nums, int left, int right)
    {
        return nums[rand() % (right - left + 1) + left];
    }
};



class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        qsort(stock, 0, stock.size() - 1, cnt);
        return { stock.begin(), stock.begin() + cnt };
    }

    void qsort(vector<int>& stock, int l, int r, int cnt)
    {
        if (l >= r) return;
        int key = getRandom(stock, l, r);
        //划分三板块
        int left = l - 1, right = r + 1, i = l;
        while (i < right)
        {
            if (stock[i] < key) swap(stock[++left], stock[i++]);
            else if (stock[i] == key) i++;
            else swap(stock[--right], stock[i]);
        }

        //选择板块
        int a = left - l + 1, b = right - left - 1;
        if (a > cnt) return qsort(stock, l, left, cnt);
        else if (a + b >= cnt) return;
        else return qsort(stock, right, r, cnt - a - b);
    }

    int getRandom(vector<int>& stock, int l, int r)
    {
        return stock[rand() % (r - l + 1) + l];
    }
};