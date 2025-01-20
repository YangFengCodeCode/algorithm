#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    unordered_map<char, char> map{ {')', '('}, {']', '['}, {'}', '{'} };
    bool isValid(string s) {
        if (s.size() % 2) return false;
        stack<char> st;
        for (auto ch : s)
        {
            if (!map.count(ch))
            {
                st.push(ch);
            }
            else
            {
                if (st.empty() || st.top() != map[ch])
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};


class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (_min.empty() || val <= _min.top())
        {
            _min.push(val);
        }
        _st.push(val);
    }

    void pop() {
        if (_st.top() == _min.top())
        {
            _min.pop();
        }
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _min.top();
    }

    stack<int> _st;
    stack<int> _min;
};

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<int> nums;
        stack<string> strs;
        strs.push("");
        int i = 0;
        while (i < n)
        {
            if (s[i] > '0' && s[i] < '9')
            {
                int tmp = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    tmp = tmp * 10 + (s[i++] - '0');
                }
                nums.push(tmp);
            }

            else if (s[i] == '[')
            {
                i++;
                string tmp;
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    tmp += s[i++];
                }
                strs.push(tmp);
            }

            else if (s[i] == ']')
            {
                int k = nums.top();
                nums.pop();
                string str = strs.top();
                strs.pop();
                while (k--)
                    strs.top() += str;
                i++;
            }

            else
            {
                if (i < n && s[i] >= 'a' && s[i] <= 'z')
                {
                    strs.top() += s[i++];
                }
            }
        }

        return strs.top();
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int top = st.top();
                st.pop();
                ans[top] = i - top;
            }
            st.push(i);
        }

        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int ans = 0;
        vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.back()] > heights[i])
            {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());
        while (--k)
        {
            heap.pop();
        }
        return heap.top();

    }
};



class Solution {
public:
    typedef pair<int, int> PST;
    struct Com
    {
        bool operator()(PST& p1, PST& p2)
        {
            if (p1.second == p2.second) return p1.first < p2.first;//大根堆
            else return p1.second > p2.second;//小根堆
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto n : nums)
        {
            hash[n]++;
        }

        priority_queue<PST, vector<PST>, Com> heap;
        for (auto e : hash)
        {
            heap.push(e);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<int> ans(k, 0);
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = heap.top().first;
            heap.pop();
        }

        return ans;


    }
};


class MedianFinder {
public:
    priority_queue<int> left;//大根堆
    priority_queue<int, vector<int>, greater<int>> right;//小根堆
    MedianFinder() {

    }

    void addNum(int num) {
        if (left.size() == right.size())
        {
            if (left.empty() || num <= left.top())
            {
                left.push(num);
            }
            else
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }

        else
        {
            if (num <= left.top())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else
            {
                right.push(num);
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size()) return (left.top() + right.top()) / 2.0;
        else return left.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */