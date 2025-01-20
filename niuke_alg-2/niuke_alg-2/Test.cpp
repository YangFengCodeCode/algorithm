#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s, tmp;
    cin >> s;
    stack<char> st;
    for (char ch : s)
    {
        if (!st.empty() && st.top() == ch) st.pop();
        else st.push(ch);
    }
    if (st.empty()) cout << 0 << endl;
    else
    {
        while (!st.empty())
        {
            tmp = st.top() + tmp;
            st.pop();
        }
    }

    cout << tmp << endl;
    return 0;

}


#include <iostream>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        stack<int> nums;
        char sign = '+';
        int num = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            }
            if (ch == '(') {
                int left = i++, count = 1;
                while (count > 0) {
                    if (s[i] == '(') count++;
                    else if (s[i] == ')') count--;
                    i++;
                }
                num = solve(s.substr(left + 1, i - left - 2));
                i--;
            }

            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                //对于字符串尾，或者加减乘，此时我们用的符号是上一次的，结算当前数字
                if (sign == '+') nums.push(num); //加法入栈
                else if (sign == '-') nums.push(-num); //减法相当于加负数
                else if (sign == '*') nums.top() *= num; //乘法与栈顶相乘
                sign = s[i]; //更新符号，若为末尾的右括号也无妨，因为马上就退出循环了
                num = 0; //重置当前数
            }

        }

        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};


#include <deque>
#include <iostream>
using namespace std;

class Queue
{
public:
    void push(const int& x)
    {
        queue.push_back(x);
    }

    void pop()
    {
        if (queue.empty()) cout << "error" << endl;
        else
        {
            cout << queue.front() << endl;
            queue.pop_front();
        }
    }

    void front()
    {
        if (queue.empty()) cout << "error" << endl;
        else
        {
            cout << queue.front() << endl;
        }
    }



    size_t size()
    {
        return queue.size();
    }

    bool empty()
    {
        return queue.empty();
    }
private:
    deque<int> queue;
};


int main() {
    int n;
    Queue q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int num;
        cin >> s;
        if (s == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            q.pop();
        }

        else if (s == "front")
        {
            q.front();
        }
    }

    return 0;
}
