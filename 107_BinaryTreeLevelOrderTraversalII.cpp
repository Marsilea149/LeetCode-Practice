//Difficulty: 4/10
//Code by myself
//Key: pre-order sort, then use std::reverse

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<vector<int>> ans;
        levelOrder(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void levelOrder(TreeNode const *root, int level, vector<vector<int>> &res)
    {
        if (!root)
            return;

        while (res.size() <= level)
        {
            res.push_back({});
        }
        res[level].push_back(root->val);
        levelOrder(root->left, level + 1, res);
        levelOrder(root->right, level + 1, res);
    }
};