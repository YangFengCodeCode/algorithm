using namespace std;
#include<iostream>









struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* prev = newhead;
        ListNode* cur = prev->next, * next = cur->next, * nnext = next->next;
        while (cur && next)
        {
            prev->next = next;
            cur->next = nnext;
            next->next = cur;

            prev = cur;
            cur = nnext;

            if (cur) next = cur->next;
            if (next) nnext = next->next;
        }

        cur = newhead->next;
        delete newhead;
        return cur;

    }
};
 
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* cur1 = l1;
//        ListNode* cur2 = l2;
//
//        ListNode* newhead = new ListNode(0);
//        ListNode* prev = newhead;
//        int t = 0;
//        while (cur1 || cur2 || t > 0)
//        {
//            if (cur1)
//            {
//                t += cur1->val;
//                cur1 = cur1->next;
//            }
//            if (cur2)
//            {
//                t += cur2->val;
//                cur2 = cur2->next;
//            }
//
//            int x = t % 10;
//            prev->next = new ListNode(x);
//            prev = prev->next;
//            t /= 10;
//        }
//
//        prev = newhead->next;
//        delete newhead;
//        return prev;
//
//    }
//};