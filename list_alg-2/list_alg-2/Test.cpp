using namespace std;
#include<iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        ListNode* slow = head, * fast = head;

        // 找到中间节点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //逆序后面链表 头插法
        ListNode* head2 = new ListNode(0);
        ListNode* cur = slow->next;
        slow->next = nullptr;//断开链表

        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = next;
        }


        //合并两个链表
        ListNode* ret = new ListNode(0);
        ListNode* prev = ret;
        ListNode* cur1 = head;
        ListNode* cur2 = head2->next;
        while (cur1)
        {
            prev->next = cur1;
            cur1 = cur1->next;
            prev = prev->next;

            if (cur2)
            {
                prev->next = cur2;
                cur2 = cur2->next;
                prev = prev->next;
            }

        }
        delete head2;
        delete ret;

    }
};



class Solution {
public:
    struct Com
    {
        bool operator()(ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Com> heap;
        for (auto& l : lists)
        {
            if (l) heap.push(l);
        }

        ListNode* ret = new ListNode(0);
        ListNode* prev = ret;
        while (!heap.empty())
        {
            ListNode* top = heap.top();
            heap.pop();
            prev->next = top;
            prev = top;
            if (top->next) heap.push(top->next);
        }

        prev = ret->next;
        delete ret;
        return prev;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = left + right >> 1;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);

        return MergeTowLists(l1, l2);
    }

    ListNode* MergeTowLists(ListNode*& l1, ListNode*& l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = new ListNode(0);
        ListNode* prev = head;

        ListNode* cur1 = l1, * cur2 = l2;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                prev->next = cur1;
                cur1 = cur1->next;
                prev = prev->next;
            }

            else
            {
                prev->next = cur2;
                cur2 = cur2->next;
                prev = prev->next;
            }
        }

        if (cur1)
        {
            prev->next = cur1;
        }

        if (cur2)
        {
            prev->next = cur2;
        }

        prev = head->next;
        delete head;
        return prev;
    }
};



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur)
        {
            cur = cur->next;
            n++;
        }

        n /= k;
        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;
        cur = head;
        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = cur;
            for (int j = 0; j < k; j++)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }

        prev->next = cur;
        prev = newhead->next;

        delete newhead;
        return prev;
    }
};