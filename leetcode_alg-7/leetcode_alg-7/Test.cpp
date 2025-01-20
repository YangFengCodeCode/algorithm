#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        auto prev = root->left;
        if (prev != nullptr)
        {
            while (prev->right != nullptr) prev = prev->right;
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};


class Solution {
public:
    TreeNode* _builTree(vector<int>& preorder, vector<int>& inorder, int& prev, int begin, int end)
    {
        if (begin > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[prev++]);
        int rooti = begin;
        while (true)
        {
            if (root->val != inorder[rooti]) rooti++;
            else break;
        }

        root->left = _builTree(preorder, inorder, prev, begin, rooti - 1);
        root->right = _builTree(preorder, inorder, prev, rooti + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prev = 0, begin = 0, end = preorder.size() - 1;
        return _builTree(preorder, inorder, prev, begin, end);
    }
};


class Solution {
public:
    unordered_map<long long, int> hash;

    int dfs(TreeNode* root, int targetSum, long long sum)
    {
        if (root == nullptr) return 0;
        sum += root->val;
        int cnt = hash[sum - targetSum];
        hash[sum]++;
        cnt += dfs(root->left, targetSum, sum) + dfs(root->right, targetSum, sum);
        hash[sum]--;
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        hash[0] = 1;
        return dfs(root, targetSum, sum);
    }
};


class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == NULL) return false;
        path.push(root);
        if (root == x) return true;
        if (getPath(root->left, x, path)) return true;
        if (getPath(root->right, x, path)) return true;
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if(root == NULL) return NULL;
        stack<TreeNode*> pPath, qPath;
        getPath(root, p, pPath);
        getPath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};


int maxPathSum(TreeNode* root, int& val)
{
    if (root == nullptr) return 0;
    int left = maxPathSum(root->left, val);
    int right = maxPathSum(root->right, val);
    int lmr = root->val + left + right;
    int ret = root->val + max(left, right);
    val = max(val, max(lmr, ret));
    return ret;
}

int maxPathSum(TreeNode* root)
{
    int val = INT_MIN;
    maxPathSum(root, val);
    return val;
}
