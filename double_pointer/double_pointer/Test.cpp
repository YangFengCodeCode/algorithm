#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
        {
            if (nums[cur])
            {
                swap(nums[++dest], nums[cur]);
            }
        }

    }
};



class Solution2 {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1, n = arr.size();
        //1 �����һ����д����
        while (cur < n)
        {
            if (arr[cur]) dest++;
            else dest += 2;
            if (dest >= n - 1) break;
            cur++;
        }

        //2 ����һ��Խ������
        if (dest > n - 1)
        {
            arr[n - 1] = 0;
            cur--; dest -= 2;
        }

        //3 �Ӻ���ǰ��д
        while (cur >= 0)
        {
            if (arr[cur])  arr[dest--] = arr[cur--];
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }

    }
};


           
class Solution {
public:
    int nSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = nSum(n);
        while (slow != fast)
        {
            slow = nSum(slow);
            fast = nSum(nSum(fast));
        }
        return slow == 1;

    }
};