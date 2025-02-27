#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<queue>
class AnimalShelf {
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        if (animal[1] == 0) cat_queue.push(animal);
        else dog_queue.push(animal);
    }

    vector<int> dequeueAny() {
        if (cat_queue.empty()) return dequeueDog();
        if (dog_queue.empty()) return dequeueCat();
        if (cat_queue.front()[0] < dog_queue.front()[0]) return dequeueCat();
        else return dequeueDog();
    }

    vector<int> dequeueDog() {
        if (dog_queue.empty()) return { -1, -1 };
        vector<int> ret = dog_queue.front();
        dog_queue.pop();
        return ret;
    }

    vector<int> dequeueCat() {
        if (cat_queue.empty()) return { -1, -1 };
        vector<int> ret = cat_queue.front();
        cat_queue.pop();
        return ret;
    }

    queue<vector<int>> dog_queue;
    queue<vector<int>> cat_queue;
};



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ret;
        for (auto str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }

        for (auto& [a, b] : hash)
        {
            ret.push_back(b);
        }

        return ret;
    }
};





class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<char, int> hash;
        char ret;
        for (int i = 0; i < arr.size(); i++)
        {
            hash[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (hash[arr[i]] == 1) return arr[i];
        }

        return ' ';

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
    void reorderList(ListNode* head) {
        if (head->next == nullptr) return;
        ListNode* fast = head;
        ListNode* mid = head;
        ListNode* prev = head;
        while (fast && fast->next)
        {
            prev = mid;
            fast = fast->next->next;
            mid = mid->next;
        }

        prev->next = nullptr;

        ListNode* cur = mid;
        ListNode* newhead = nullptr;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }

        ListNode* rhead = head;
        ListNode* tail = head;
        ListNode* cur1 = head->next, * cur2 = newhead;
        while (cur1 && cur2)
        {
            tail->next = cur2;
            cur2 = cur2->next;
            tail = tail->next;
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;
        }

        tail->next = cur2;
        head = rhead;
    }
};