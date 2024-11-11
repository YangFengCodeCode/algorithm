#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};


class Solution {
public:
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return ret;
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
};



class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);

        root->left = right;
        root->right = left;
        return root;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSameTree(root->left, root->right);
    }
};



class Solution {
public:
    int len = 0;
    int dfs(TreeNode* root)
    {
        if (root == nullptr) return -1;
        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;
        len = max(len, left + right);
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return len;

    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = q.front();
                v.push_back(front->val);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                q.pop();
            }
            ret.push_back(v);
        }

        return ret;
    }
};



class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreatBST(0, nums.size() - 1, nums);
    }

    TreeNode* CreatBST(int left, int right, vector<int>& nums)
    {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = CreatBST(left, mid - 1, nums);
        root->right = CreatBST(mid + 1, right, nums);

        return root;
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
        if (root == nullptr) return true;
        long long x = root->val;
        return x > left && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                TreeNode* front = q.front();
                q.pop();
                if (k == size - 1) ret.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return ret;
    }
};