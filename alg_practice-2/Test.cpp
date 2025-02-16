#include<iostream>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        st_push.push(x);
    }

    int pop() {
        if (st_pop.empty())
        {
            while (!st_push.empty())
            {
                int t = st_push.top();
                st_push.pop();
                st_pop.push(t);
            }
        }
        int ret = st_pop.top();
        st_pop.pop();
        return ret;

    }

    int peek() {
        if (st_pop.empty())
        {
            while (!st_push.empty())
            {
                int t = st_push.top();
                st_push.pop();
                st_pop.push(t);
            }
        }
        return st_pop.top();
    }

    bool empty() {
        return st_push.empty() && st_pop.empty();
    }

    stack<int> st_push;
    stack<int> st_pop;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


class Solution {
public:
    int multiply(int A, int B) {
        int ans = 0;
        while (B > 0)
        {
            if (B & 1) ans += A;
            A <<= 1;
            B >>= 1;
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (!ret.size() || ret.back()[1] < left)
            {
                ret.push_back({ left, right });
            }
            else
            {
                ret.back()[1] = max(ret.back()[1], right);
            }
        }

        return ret;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, ret = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
            else hash[sum] += i;
        }

        return ret;
    }
};