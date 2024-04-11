#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> q;
        q.push(root);
        if (root == nullptr) return ret;

        while (q.size())
        {
            vector<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node* node = q.front();
                tmp.push_back(node->val);
                q.pop();
                for (Node* newnode : node->children)
                {
                    if (newnode != nullptr)
                        q.push(newnode);
                }
            }

            ret.push_back(tmp);
        }

        return ret;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if (root == nullptr) return ret;

        q.push(root);
        int level = 1;
        while (q.size())
        {
            vector<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 0)
            {
                reverse(tmp.begin(), tmp.end());
            }
            level++;
            ret.push_back(tmp);
        }

        return ret;

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
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, unsigned int>> q;
        q.push_back({ root, 1 });
        unsigned int ret = 0;

        while (q.size())
        {
            auto& [x1, y1] = q.front();
            auto& [x2, y2] = q.back();
            ret = max(ret, y2 - y1 + 1);

            vector<pair<TreeNode*, unsigned int>> tmp;
            for (auto& [x, y] : q)
            {
                if (x->left) tmp.push_back({ x->left, y * 2 });
                if (x->right) tmp.push_back({ x->right, y * 2 + 1 });
            }

            q = tmp;
        }

        return ret;

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