#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto e : bills)
        {
            if (e == 5) five++;
            else if (e == 10)
            {
                if (five >= 1)
                {
                    five--;
                    ten++;
                }

                else return false;
            }

            else
            {
                if (ten && five)
                {
                    ten--;
                    five--;
                }

                else if (five >= 3)
                {
                    five -= 3;
                }

                else return false;
            }
        }

        return true;

    }
};

#include<queue>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0.0;
        int count = 0;
        priority_queue<double> heap;
        for (auto e : nums)
        {
            sum += e;
            heap.push(e);
        }

        sum /= 2.0;
        while (sum > 0)
        {
            double t = heap.top() / 2.0;
            sum -= t;
            heap.pop();
            heap.push(t);
            count++;
        }

        return count;

    }
};



class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto num : nums) v.push_back(to_string(num));

        sort(v.begin(), v.end(), [](const string& s1, const string& s2) {return s1 + s2 > s2 + s1; });
        string ret;
        for (auto s : v) ret += s;
        if (ret[0] == '0') return "0";
        else return ret;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int ret = 0, left = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int right = nums[i + 1] - nums[i];
            if (right == 0) continue;
            if (left * right <= 0) ret++;
            left = right;
        }

        return ret + 1;

    }
};
