#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
using namespace std;

class Queue
{
private:
    int* data;
    int count;
    int size;
    int head, near;
public:
    Queue(int capacity)
    {
        data = new int[capacity];
        size = capacity;
        count = 0;
        head = near = 0;
    }

    ~Queue() { delete[] data; }

    void push(int x)
    {
        if (isfull()) { cout << "full" << endl; return; }
        data[near] = x;
        near = (near + 1) % size;
        count++;
    }

    void pop()
    {
        if (isempty()) { cout << "empty" << endl; return; }
        cout << data[head] << endl;
        head = (head + 1) % size;
        count--;
    }

    void front()
    {
        if (isempty()) { cout << "empty" << endl; return; }
        cout << data[head] << endl;
    }

    bool isempty()
    {
        return count == 0;
    }
    bool isfull()
    {
        return count == size;
    }


};
int main() {
    int n, m;
    cin >> n >> m;
    Queue q(n);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
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
