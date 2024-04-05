#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>

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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int presum)
    {
        presum = presum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return presum;
        int ret = 0;
        if (root->left) ret += dfs(root->left, presum);
        if (root->right) ret += dfs(root->right, presum);
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
        {
            root = nullptr;
        }
        return root;
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
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        bool cur = false;
        if (root->val > prev) cur = true;
        prev = root->val;
        bool right = isValidBST(root->right);
        return cur && left && right;
    }
};


class Solution {
public:
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (left == false) return false;
        bool cur = false;
        if (root->val > prev) cur = true;
        if (cur == false) return false;
        prev = root->val;
        bool right = isValidBST(root->right);
        return cur && left && right;
    }
};

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
    int ret, count;
public:

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }

    void dfs(TreeNode* root)
    {
        if (root == nullptr || count == 0) return;
        dfs(root->left);
        count--;
        if (count == 0) ret = root->val;
        dfs(root->right);
    }
};


class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};



class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int i)
    {
        if (i == nums.size())
        {
            ret.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();

        dfs(nums, i + 1);
    }
};


class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int i)
    {
        if (i == nums.size())
        {
            ret.push_back(path);
            return;
        }

        ret.push_back(path);
        for (int pos = i; pos < nums.size(); pos++)
        {
            path.push_back(nums[pos]);
            dfs(nums, pos + 1);
            path.pop_back();
        }
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
    vector<string> ret;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return ret;
        string path;
        dfs(root, path);
        return ret;
    }

    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(path);
            return;
        }

        path += "->";
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }
};