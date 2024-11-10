#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, * cur2 = l2;
        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;

        int t = 0;
        while (cur1 || cur2 || t)
        {
            if (cur1)
            {
                t += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2)
            {
                t += cur2->val;
                cur2 = cur2->next;
            }
            int x = t % 10;
            ListNode* node = new ListNode(x);
            prev->next = node;
            prev = node;
            t /= 10;
        }

        prev = newhead->next;
        delete newhead;
        return prev;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, * fast = head, * prev = nullptr;
        while (n)
        {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
            n--;
        }
        while (fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (slow == head) return slow->next;
        prev->next = slow->next;
        delete slow;
        return head;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* prev = newhead, * cur = head, * next = cur->next, * nnext = next->next;
        while (cur && next)
        {
            prev->next = next;
            next->next = cur;
            cur->next = nnext;

            prev = cur;
            cur = nnext;
            if (cur) next = cur->next;
            if (next) nnext = next->next;
        }

        prev = newhead->next;
        delete newhead;
        return prev;
    }
};

#include<map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead = NULL;
        Node* tail = newhead, * cur = head;
        map<Node*, Node*> hash;

        while (cur)
        {
            if (tail == NULL)
            {
                newhead = tail = new Node(cur->val);
            }
            else
            {
                tail->next = new Node(cur->val);
                tail = tail->next;
            }
            hash.insert(make_pair(cur, tail));
            cur = cur->next;
        }

        tail = newhead;
        cur = head;
        while (cur)
        {
            if (cur->random == NULL)
            {
                tail->random = NULL;
            }

            else
            {
                tail->random = hash[cur->random];
            }

            tail = tail->next;
            cur = cur->next;
        }

        return newhead;
    }
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 0;
        while (cur)
        {
            cur = cur->next;
            count++;
        }

        int n = count / k;
        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead;
        cur = head;
        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = cur;
            for (int j = 0; j < k; j++)
            {
                ListNode* next = cur->next;
                cur->next = tail->next;
                tail->next = cur;
                cur = next;
            }

            tail = tmp;
        }

        tail->next = cur;
        tail = newhead->next;
        delete newhead;
        return tail;
    }
};



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }

    ListNode* mergesort(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* mid = head, * fast = head->next;
        while (fast && fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* cur1 = head, * cur2 = mid->next;
        if (mid) mid->next = nullptr;
        ListNode* head1 = mergesort(cur1);
        ListNode* head2 = mergesort(cur2);

        //¹é²¢
        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                tail->next = new ListNode(head1->val);
                head1 = head1->next;
            }
            else
            {
                tail->next = new ListNode(head2->val);
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1) tail->next = head1;
        if (head2) tail->next = head2;

        tail = newhead->next;
        delete newhead;
        return tail;
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

        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead;

        while (!heap.empty())
        {
            ListNode* top = heap.top();
            heap.pop();
            tail->next = top;
            tail = top;
            if (top->next) heap.push(top->next);
        }

        tail = newhead->next;
        delete newhead;
        return tail;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(0, lists.size() - 1, lists);
    }

    ListNode* mergeSort(int left, int right, vector<ListNode*>& lists)
    {
        if (left == right) return lists[left];
        if (left > right) return nullptr;

        int mid = left + right >> 1;
        ListNode* cur1 = mergeSort(left, mid, lists);
        ListNode* cur2 = mergeSort(mid + 1, right, lists);

        //¹é²¢
        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                tail->next = cur1;
                cur1 = cur1->next;
            }

            else
            {
                tail->next = cur2;
                cur2 = cur2->next;
            }

            tail = tail->next;
        }

        if (cur1) tail->next = cur1;
        if (cur2) tail->next = cur2;
        tail = newhead->next;
        delete newhead;
        return tail;
    }
};



class Node
{
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k = 0, int v = 0) :key(k), value(v) {}
};

#include<unordered_map>
class LRUCache {
private:
    int capacity;
    Node* head;
    unordered_map<int, Node*> hash;

    void remove(Node* x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node* x)
    {
        Node* next = head->next;
        x->next = next;
        next->prev = x;
        head->next = x;
        x->prev = head;
    }

    Node* get_node(int key)
    {
        if (!hash.count(key)) return nullptr;
        Node* node = hash[key];
        remove(node);
        push_front(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(new Node()) {
        head->prev = head;
        head->next = head;
    }

    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        Node* node = get_node(key);
        if (node)
        {
            node->value = value;
            return;
        }

        hash[key] = node = new Node(key, value);
        push_front(node);
        if (hash.size() > capacity)
        {
            Node* back_node = head->prev;
            hash.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
};