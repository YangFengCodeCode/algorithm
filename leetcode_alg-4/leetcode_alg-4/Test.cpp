#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



 struct ListNode {
    int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    int Count(ListNode* list)
    {
        int count = 0;
        ListNode* cur = list;
        while (cur)
        {
            count++;
            cur = cur->next;
        }

        return count;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = Count(headA), lenB = Count(headB);
        int k = abs(lenA - lenB);
        ListNode* curA = headA, * curB = headB;

        if (lenA > lenB)
        {
            while (k--) curA = curA->next;
        }
        else
        {
            while (k--) curB = curB->next;
        }

        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
    }
};




class Solution {
public:
    bool hasCycle(ListNode* head) {
        struct ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                struct ListNode* meet = slow;
                while (meet != head)
                {
                    meet = meet->next;
                    head = head->next;
                }

                if (meet == head) return true;
            }
        }

        return false;

    }
};



class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* meet = slow;
                while (head != meet)
                {
                    head = head->next;
                    meet = meet->next;
                }

                return meet;
            }
        }

        return NULL;

    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        else
        {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newNode = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // 创建新链表的头节点
        ListNode* newHead = new ListNode(head->val);
        ListNode* current = newHead;
        ListNode* original = head->next;

        // 遍历原链表，复制节点
        while (original != nullptr) {
            ListNode* newNode = new ListNode(original->val);
            current->next = newNode;  // 将新节点链接到新链表
            current = newNode;        // 更新 current 指针
            original = original->next; // 更新原链表指针
        }
        ListNode* cur2 = reverse(head);

        while (newHead || cur2)
        {
            if (newHead == nullptr && cur2) return false;
            if (newHead && cur2 == nullptr) return false;
            if (newHead->val != cur2->val) return false;
            //cout << newHead->val << " " << cur2->val << endl;
            newHead = newHead->next;
            cur2 = cur2->next;
        }

        return true;

    }
};



class Solution {
public:

    ListNode* Mid(ListNode* head)
    {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* Reverse(ListNode* head)
    {
        ListNode* newhead = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }

        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* midNode = Mid(head);
        ListNode* newhead = Reverse(midNode);
        while (head && newhead)
        {
            if (head->val != newhead->val) return false;
            head = head->next;
            newhead = newhead->next;
        }

        return true;
    }
};