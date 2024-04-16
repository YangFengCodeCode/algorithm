using namespace std;
#include<iostream>
#include<vector>

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root == nullptr) return ret;

        q.push(root);
        while (q.size())
        {
            int sz = q.size();
            int tmp = INT_MIN;
            for (int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                tmp = max(tmp, node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};


#include<queue>

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto e : nums)
        {
            heap.push(e);
            if (heap.size() > k) heap.pop();
        }

    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > _k) heap.pop();
        return heap.top();
    }
};



#include<map>
class Solution {
public:
    struct kvCom
    {
        bool operator()(const pair<string, int>& v1, const pair<string, int>& v2)
        {
            return v1.second > v2.second || (v1.second == v2.second && v1.first < v2.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mapWord;
        for (auto& e : words)
        {
            mapWord[e]++;
        }

        vector<pair<string, int>> v(mapWord.begin(), mapWord.end());
        sort(v.begin(), v.end(), kvCom());
        auto it = v.begin();
        vector<string> v0;
        while (k--)
        {
            v0.push_back(it->first);
            it++;
        }
        return v0;

    }
};




class Solution {
    typedef pair<string, int> PSI;
public:

    struct com
    {
        bool operator()(const PSI& p1, const PSI& p2)
        {
            if (p1.second == p2.second) return p1.first < p2.first;//大根堆
            return p1.second > p2.second;//小根堆
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (auto& e : words)
        {
            hash[e]++;
        }

        priority_queue<PSI, vector<PSI>, com> heap;
        for (auto& e : hash)
        {
            heap.push(e);
            if (heap.size() > k) heap.pop();
        }

        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = heap.top().first;
            heap.pop();
        }
        return ret;

    }
};




class MedianFinder
{
    priority_queue<int> left; // ⼤根堆
    priority_queue<int, vector<int>, greater<int>> right; // ⼩根堆
public:
    MedianFinder()
    {}

    void addNum(int num)
    {
        // 分类讨论即可
        if (left.size() == right.size()) // 左右两个堆的元素个数相同
        {
            if (left.empty() || num <= left.top()) // 放 left ⾥⾯
            {
                left.push(num);
            }
            else
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else
        {
            if (num <= left.top())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else
            {
                right.push(num);
            }
        }
    }

    double findMedian()
    {
        if (left.size() == right.size()) return (left.top() + right.top()) / 2.0;
        else return left.top();
    }
};