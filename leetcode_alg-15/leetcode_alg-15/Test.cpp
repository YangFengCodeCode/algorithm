#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            val ^= nums[i];
        }

        return val;

    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int x;
        for (int i = 0; i < nums.size(); i++)
        {
            if (vote == 0) x = nums[i];
            vote += x == nums[i] ? 1 : -1;
        }

        return x;

    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        int i = 0;
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), tail = n - 2, head;
        while (tail >= 0 && nums[tail] >= nums[tail + 1]) tail--;
        if (tail >= 0)
        {
            head = tail, tail = n - 1;
            while (nums[head] >= nums[tail]) tail--;
            swap(nums[head], nums[tail]);
        }

        reverse(nums.begin() + head + 1, nums.end());
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int pre1 = 0;
        int pre2 = slow;
        while (pre1 != pre2) {
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre1;
    }
};