using namespace std;
#include<iostream>
#include<vector>

class Solution {
    vector<int> tmp;
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        mergesort(0, n - 1, nums);
        return nums;
    }

    void mergesort(int left, int right, vector<int>& nums)
    {
        if (left >= right) return;

        //1. 选基准点
        int mid = (right + left) >> 1;

        //2. 排序
        mergesort(left, mid, nums);
        mergesort(mid + 1, right, nums);

        //3. 合并两个有序数组
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            tmp[i++] = nums[cur1] >= nums[cur2] ? nums[cur2++] : nums[cur1++];
        }

        while (cur1 <= mid)  tmp[i++] = nums[cur1++];

        while (cur2 <= right)    tmp[i++] = nums[cur2++];

        //4. 还原
        for (int i = left; i <= right; i++)
        {
            nums[i] = tmp[i - left];
        }
    }
};






class Solution {
    int tmp[50010];
    //int ret = 0;
public:
    int reversePairs(vector<int>& record) {
        return mergesort(record, 0, record.size() - 1);
    }

    int mergesort(vector<int>& record, int left, int right)
    {
        if (left >= right) return 0;
        int ret = 0;
        int mid = (left + right) >> 1;

        ret += mergesort(record, left, mid);
        ret += mergesort(record, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (record[cur1] > record[cur2])
            {
                ret += mid - cur1 + 1;
                tmp[i++] = record[cur2++];
            }

            else
            {
                tmp[i++] = record[cur1++];
            }
        }

        while (cur1 <= mid) tmp[i++] = record[cur1++];
        while (cur2 <= right) tmp[i++] = record[cur2++];

        for (int i = left; i <= right; i++)
        {
            record[i] = tmp[i - left];
        }

        return ret;
    }
};





class Solution {
    vector<int> ret;
    vector<int> index;
    int tmpNums[500010];
    int tmpIndex[500010];
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ret.resize(n);
        index.resize(n);
        for (int i = 0; i < n; i++)
        {
            index[i] = i;
        }
        mergesort(nums, 0, n - 1);
        return ret;
    }

    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] > nums[cur2])
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmpNums[i] = nums[cur1];
                tmpIndex[i++] = index[cur1++];
            }

            else
            {
                tmpNums[i] = nums[cur2];
                tmpIndex[i++] = index[cur2++];
            }
        }

        while (cur1 <= mid)
        {
            tmpNums[i] = nums[cur1];
            tmpIndex[i++] = index[cur1++];
        }

        while (cur2 <= right)
        {
            tmpNums[i] = nums[cur2];
            tmpIndex[i++] = index[cur2++];
        }

        for (int j = left; j <= right; j++)
        {
            nums[j] = tmpNums[j - left];
            index[j] = tmpIndex[j - left];
        }

    }
};



class Solution {
    int tmp[50010];
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }

    int mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return 0;
        int mid = (left + right) >> 1;

        int ret = 0;
        ret += mergesort(nums, left, mid);
        ret += mergesort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid)
        {
            while (cur2 <= right && nums[cur2] >= nums[cur1] / 2.0)
            {
                cur2++;
            }

            if (cur2 > right) break;
            ret += right - cur2 + 1;
            cur1++;
        }

        cur1 = left, cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
        {
            tmp[i++] = nums[cur1] > nums[cur2] ? nums[cur1++] : nums[cur2++];
        }

        while (cur1 <= mid) tmp[i++] = nums[cur1++];
        while (cur2 <= right) tmp[i++] = nums[cur2++];

        for (int i = left; i <= right; i++)
        {
            nums[i] = tmp[i - left];
        }

        return ret;

    }
};