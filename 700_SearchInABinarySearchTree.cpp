/** Difficulty: 3/10
 * Key notion: 
 *  - recursive call
 *  - property of Binary Search Tree (left val < root val < right val)
 * 
 * TIme complexity: log(n) ~ n (if BST well balanced: log(n))
 * Space complexity: log(n) ~ n
 */

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;

        if (root->val > val)
            return searchBST(root->left, val);
        else if (root->val < val)
            return searchBST(root->right, val);
        else
            return root;
    }
};