#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

//贪心+动态规划+广度优先搜索
//贪心：搜索使得dp值更小的节点，忽略使得dp值增大的节点，优先遍历dp值小的节点（优先队列）
//动态规划：dp[i]保存从1到当前节点i的距离
//广度优先搜索：遍历每个节点的可达节点i，同时将满足贪心原则的{dp[i],i}放到优先队列中

int main()
{
    int n, m;
    cin >> n >> m;
    // dp[i]表示从1到i的距离
    vector<int> dp(5001, INT32_MAX);
    //保存双向连接关系
    unordered_map<int, vector<pair<int, int>>> um;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        um[u].push_back({ v, w });
        um[v].push_back({ u, w });
    }
    //按照距离排序的小顶堆，second表示当前位置，first表示从1到当前位置的距离
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dp[1] = 0;
    //从1到1的距离是0
    pq.push({ 0, 1 });
    while (!pq.empty())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        int cur = t.second;
        //如果现在的dp值小于入队时的dp值t.first，则跳过循环
        if (dp[cur] < t.first)
            continue;
        //遍历cur的可达节点
        vector<pair<int, int>>& avai = um[cur];
        for (int i = 0; i < avai.size(); i++)
        {
            int uv = avai[i].first; //可达节点
            int w = avai[i].second;
            //如果点1——>...——>cur——>uv的距离小于点1——>...——>uv的距离，更新dp[uv]
            if (dp[cur] + w < dp[uv])
            {
                dp[uv] = dp[cur] + w;
                pq.push({ dp[uv], uv });
            }
        }
    }
    if (dp[n] != INT32_MAX)
        cout << dp[n];
    else
        cout << -1;
}



/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<int> preorder, inorder, backorder;
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> ret;
        Preorder(root);
        Inorder(root);
        Backorder(root);
        ret.push_back(preorder);
        ret.push_back(inorder);
        ret.push_back(backorder);
        return ret;
    }

    void Preorder(TreeNode* root)
    {
        if (root == nullptr) return;
        preorder.push_back(root->val);
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(TreeNode* root)
    {
        if (root == nullptr) return;
        Inorder(root->left);
        inorder.push_back(root->val);
        Inorder(root->right);
    }

    void Backorder(TreeNode* root)
    {
        if (root == nullptr) return;
        Backorder(root->left);
        Backorder(root->right);
        backorder.push_back(root->val);
    }
};


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <unordered_map>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param inorder int整型vector 中序遍历序列
     * @param postorder int整型vector 后序遍历序列
     * @return TreeNode类
     */

    unordered_map<int, int> hash;
    int post_index;

    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder)
    {
        if (in_left > in_right) return nullptr;
        int val = postorder[post_index];
        TreeNode* root = new TreeNode(val);
        post_index--;
        int index = hash[val];
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // write code here
        post_index = (int)postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] = i;
        }

        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};