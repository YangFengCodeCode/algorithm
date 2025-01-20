#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, button = m - 1;
        vector<int> ret;
        while (left <= right && top <= button)
        {
            //从左往右
            for (int i = left; i <= right; i++)
                ret.push_back(matrix[top][i]);
            top++;

            //从上往下
            for (int i = top; i <= button; i++)
                ret.push_back(matrix[i][right]);
            right--;

            //从右往左
            if (top <= button)
            {
                for (int i = right; i >= left; i--)
                    ret.push_back(matrix[button][i]);
            }
            button--;

            //从下往上
            if (left <= right)
            {
                for (int i = button; i >= top; i--)
                    ret.push_back(matrix[i][left]);
            }
            left++;
        }

        return ret;

    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix)
        {
            vector<int>::iterator it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target)
            {
                return true;
            }
        }

        return false;

    }
};



