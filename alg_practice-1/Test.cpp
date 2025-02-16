#include<iostream>
using namespace std;
#include<stack>

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        if (min.empty() || val <= min.top())
        {
            min.push(val);
        }
        st.push(val);
    }

    void pop() {
        if (st.top() == min.top()) min.pop();
        if (!st.empty()) st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min.top();
    }

    stack<int> st;
    stack<int> min;
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
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> st;
        int num;
        for (auto e : tokens)
        {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if (e == "+") num = op2 + op1;
                if (e == "-") num = op2 - op1;
                if (e == "*") num = op2 * op1;
                if (e == "/") num = op2 / op1;
                st.push(num);
            }
            else
            {
                num = stoi(e);
                st.push(num);
            }
        }

        return st.top();
    }
};


class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26) return false;
        int bitMap = 0;
        for (int i = 0; i < astr.size(); i++)
        {
            int num = astr[i] - 'a';
            if ((bitMap >> num) & 1 == 1) return false;
            bitMap |= (1 << num);
        }
        return true;
    }
};