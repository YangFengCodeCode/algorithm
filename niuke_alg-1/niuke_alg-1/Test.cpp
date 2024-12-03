#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

#include <iomanip>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param tokens string字符串vector
     * @return int整型
     */
    int evalRPN(vector<string>& tokens) {
        // write code here
        stack<long long> st;
        for (auto s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                long long result;
                long long x1 = st.top();
                st.pop();
                long long x2 = st.top();
                st.pop();
                if (s == "+") result = x2 + x1;
                else if (s == "-") result = x2 - x1;
                else if (s == "*") result = x2 * x1;
                else if (s == "/")result = x2 / x1;
                st.push(result);
            }
            else st.push(stoi(s));

        }
        return st.top();
    }
};



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(a);
            }
            else
            {
                if (!st.empty())
                {
                    char ch = st.top();
                    if ((ch == '(' && a == ')') || (ch == '[' && a == ']') || (ch == '{' && a == '}')) st.pop();
                    else return false;
                }
                else return false;
            }
        }
        return st.empty();
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        int pushi = 0, count = 0, popi = 0;
        stack<int> st;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi++]);
            while (!st.empty() && st.top() == popV[popi])
            {
                popi++;
                st.pop();
                count++;
            }
        }
        return count == popV.size();
    }
};




class Stack {
public:
    void push(int x) {
        v.push_back(x);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v.back();
    }

    bool empty() {
        return v.empty();
    }

private:
    vector<int> v;
};

int main() {
    int n;
    cin >> n;
    Stack st;
    n += 1;
    while (n--) {
        string s;
        getline(cin, s);
        size_t pos = s.find(" ");
        string op = s.substr(0, pos);
        int num = 0;
        if (pos != string::npos) {
            string tmp = s.substr(pos + 1);
            for (int i = 0; i < tmp.size(); i++) {
                char a = tmp[i];
                num = num * 10 + (a - '0');
            }
        }

        if (op == "push") st.push(num);

        else if (op == "pop") {
            if (st.empty()) cout << "error" << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }

        else if (op == "top") {
            if (st.empty()) cout << "error" << endl;
            else {
                cout << st.top() << endl;
            }
        }
    }

}