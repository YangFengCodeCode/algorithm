#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

//̰��+��̬�滮+�����������
//̰�ģ�����ʹ��dpֵ��С�Ľڵ㣬����ʹ��dpֵ����Ľڵ㣬���ȱ���dpֵС�Ľڵ㣨���ȶ��У�
//��̬�滮��dp[i]�����1����ǰ�ڵ�i�ľ���
//�����������������ÿ���ڵ�Ŀɴ�ڵ�i��ͬʱ������̰��ԭ���{dp[i],i}�ŵ����ȶ�����

int main()
{
    int n, m;
    cin >> n >> m;
    // dp[i]��ʾ��1��i�ľ���
    vector<int> dp(5001, INT32_MAX);
    //����˫�����ӹ�ϵ
    unordered_map<int, vector<pair<int, int>>> um;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        um[u].push_back({ v, w });
        um[v].push_back({ u, w });
    }
    //���վ��������С���ѣ�second��ʾ��ǰλ�ã�first��ʾ��1����ǰλ�õľ���
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dp[1] = 0;
    //��1��1�ľ�����0
    pq.push({ 0, 1 });
    while (!pq.empty())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        int cur = t.second;
        //������ڵ�dpֵС�����ʱ��dpֵt.first��������ѭ��
        if (dp[cur] < t.first)
            continue;
        //����cur�Ŀɴ�ڵ�
        vector<pair<int, int>>& avai = um[cur];
        for (int i = 0; i < avai.size(); i++)
        {
            int uv = avai[i].first; //�ɴ�ڵ�
            int w = avai[i].second;
            //�����1����>...����>cur����>uv�ľ���С�ڵ�1����>...����>uv�ľ��룬����dp[uv]
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode�� the root of binary tree
     * @return int����vector<vector<>>
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param inorder int����vector �����������
     * @param postorder int����vector �����������
     * @return TreeNode��
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