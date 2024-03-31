#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<list>

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        dfs(A, B, C, A.size());
    }

    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        dfs(A, C, B, n - 1);
        C.push_back(A.back());
        A.pop_back();
        dfs(B, A, C, n - 1);
    }
};



//Definition for singly-linked list.
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/


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
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

    }
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
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / pow(x, -(long long)n) : pow(x, n);
    }

    double pow(double x, long long int n) {
        if (n == 0) return 1.0;
        auto ret = myPow(x, n / 2);
        return n % 2 == 0 ? ret * ret : ret * ret * x;

    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return root->val == 0 ? false : true;
        bool ret1 = evaluateTree(root->left);
        bool ret2 = evaluateTree(root->right);
        if (root->val == 2) return ret1 || ret2;
        else return ret1 && ret2;
    }
};