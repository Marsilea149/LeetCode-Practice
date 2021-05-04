//Code from Huahua: https://zxi.mytechroad.com/blog/leetcode/leetcode-102-binary-tree-level-order-traversal/
//Difficulty: 4/10
//Trick: think about putting level as parameter
//Theme: tree

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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        dfs(root, 0 /*depth*/, res);
        return res;
    }

private:
    void dfs(TreeNode const *node, int depth, vector<vector<int>> &res)
    {
        if (!node)
            return;

        while (res.size() <= depth)
            res.push_back({});

        res[depth].push_back(node->val);
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
};