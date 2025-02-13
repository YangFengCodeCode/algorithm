#include<iostream>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortNums(nums);
        sort(nums.begin(), nums.end());
        int l = 0;
        while (nums[l] == sortNums[l])
        {
            l++;
            if (l == nums.size()) return 0;
        }

        int r = nums.size() - 1;
        while (nums[r] == sortNums[r])
        {
            r--;
        }

        return r - l + 1;
    }
};



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int l = 0, r = n - 1, t = 0, b = n - 1;
        int num = 0;
        while (num != n * n)
        {
            for (int i = l; i <= r; i++) ret[t][i] = ++num;

            t++;
            for (int i = t; i <= b; i++) ret[i][r] = ++num;

            r--;
            for (int i = r; i >= l; i--) ret[b][i] = ++num;

            b--;
            for (int i = b; i >= t; i--) ret[i][l] = ++num;

            l++;
        }

        return ret;

    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret(m * n);

        int l = 0, r = n - 1, t = 0, b = m - 1;
        int j = 0;
        while (l <= r && t <= b)
        {
            for (int i = l; i <= r; i++) ret[j++] = matrix[t][i];

            t++;
            for (int i = t; i <= b; i++) ret[j++] = matrix[i][r];

            r--;
            if (t <= b)
                for (int i = r; i >= l; i--) ret[j++] = matrix[b][i];

            b--;
            if (l <= r)
                for (int i = b; i >= t; i--) ret[j++] = matrix[i][l];

            l++;
        }

        return ret;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0;
        int ret = 0;
        hash[0] = 1;
        for (auto e : nums)
        {
            sum += e;
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }

        return ret;
    }
};