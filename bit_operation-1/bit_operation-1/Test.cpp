#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26) return false;
        int bitMap = 0;
        for (int i = 0; i < astr.size(); i++)
        {
            int n = astr[i] - 'a';
            if ((bitMap >> n) & 1 == 1) return false;
            bitMap |= (1 << n);
        }
        return true;

    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e : nums) ret ^= e;
        for (int i = 0; i <= nums.size(); i++) ret ^= i;
        return ret;
    }
};




class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            int x = a ^ b;//算出无进制相加的结果
            int carry = (a & b) << 1; //算出进位
            a = x;
            b = carry;
        }
        return a;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto e : nums)
                if (((e >> i) & 1) == 1) sum++;
            if (sum % 3 == 1) ret |= (1 << i);
        }
        return ret;

    }
};


class Solution
{
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        // 1. 将所有的数异或在⼀起
        int tmp = 0;
        for (auto x : nums) tmp ^= x;
        for (int i = 1; i <= nums.size() + 2; i++) tmp ^= i;
        // 2. 找出 a，b 中⽐特位不同的那⼀位
        int diff = 0;
        while (1)
        {
            if (((tmp >> diff) & 1) == 1) break;
            else diff++;
        }
        // 3. 根据 diff 位的不同，将所有的数划分为两类来异或
        int a = 0, b = 0;
        for (int x : nums)
            if (((x >> diff) & 1) == 1) b ^= x;
            else a ^= x;
        for (int i = 1; i <= nums.size() + 2; i++)
            if (((i >> diff) & 1) == 1) b ^= i;
            else a ^= i;
        return { a, b };
    }
};
