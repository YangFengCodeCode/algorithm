#include <cstddef>
#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(const int& x)
        :next(nullptr), val(x) {}
};

class List
{
public:
    void insert(int x, int y)
    {
        ListNode* tail = _head;
        ListNode* prev = tail;
        tail = tail->next;
        ListNode* newNode = new ListNode(y);
        while (tail != nullptr)
        {
            if (tail->val == x) break;
            prev = tail;
            tail = tail->next;
        }
        prev->next = newNode;
        newNode->next = tail;
    }

    void del(int x)
    {
        ListNode* tail = _head;
        ListNode* prev = tail;
        tail = tail->next;
        while (tail != nullptr)
        {
            if (tail->val == x) break;
            prev = tail;
            tail = tail->next;
        }
        prev->next = tail->next;
        delete tail;
    }

    void Print()
    {

        ListNode* tail = _head->next;
        if (tail == nullptr)
        {
            cout << "NULL";
            return;
        }
        while (tail != nullptr)
        {
            cout << tail->val << " ";
            tail = tail->next;
        }
    }

private:
    ListNode* _head = new ListNode(0);

};

int main() {
    List list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "insert")
        {
            int x, y;
            cin >> x >> y;
            list.insert(x, y);
        }
        if (op == "delete")
        {
            int x;
            cin >> x;
            list.del(x);
        }
    }

    list.Print();
    return 0;

}



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @return ListNode��
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here
        ListNode* newHead = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};