#include<iostream>
using namespace std;

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
     * @param pHead1 ListNode��
     * @param pHead2 ListNode��
     * @return ListNode��
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead;
        while (pHead1 && pHead2)
        {
            if (pHead1->val > pHead2->val)
            {
                tail->next = pHead2;
                tail = tail->next;
                pHead2 = pHead2->next;
            }
            else
            {
                tail->next = pHead1;
                tail = tail->next;
                pHead1 = pHead1->next;
            }
        }
        if (pHead1)
        {
            tail->next = pHead1;
        }
        if (pHead2)
        {
            tail->next = pHead2;
        }

        return newhead->next;
    }
};


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
     * @param val int����
     * @return ListNode��
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if (head->val == val) return head->next;
        ListNode* tail = head;
        ListNode* prev = tail;
        tail = tail->next;
        while (tail)
        {
            if (tail->val == val) break;
            prev = tail;
            tail = tail->next;
        }
        prev->next = tail->next;
        return head;

    }
};


#include <iostream>
#include <unordered_map>
#include <vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    vector<int> in(n + 1, 0);
    unordered_map<int, vector<int>> hash;
    vector<int> ret;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        in[v]++;
        hash[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        ret.push_back(t);
        for (auto e : hash[t])
        {
            in[e]--;
            if (in[e] == 0) q.push(e);
        }
    }

    if (ret.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ret[i];
            if (i != n - 1) cout << ' ';
        }
    }
    else
    {
        cout << -1;
    }
    return 0;

}
