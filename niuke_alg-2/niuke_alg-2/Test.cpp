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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���ر��ʽ��ֵ
     * @param s string�ַ��� ������ı��ʽ
     * @return int����
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
                //�����ַ���β�����߼Ӽ��ˣ���ʱ�����õķ�������һ�εģ����㵱ǰ����
                if (sign == '+') nums.push(num); //�ӷ���ջ
                else if (sign == '-') nums.push(-num); //�����൱�ڼӸ���
                else if (sign == '*') nums.top() *= num; //�˷���ջ�����
                sign = s[i]; //���·��ţ���Ϊĩβ��������Ҳ�޷�����Ϊ���Ͼ��˳�ѭ����
                num = 0; //���õ�ǰ��
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
