// Difficulty: 2/10
// Theme: tree

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }

private:
    /** Helper function: check if left subtree is symmetric to right subtree
     *  root is the same
     *  left child = right child 
     *  right child = left child
     */

    bool isSymmetric(TreeNode const *left, TreeNode const *right)
    {
        if (!left && !right)
            return true;

        if ((!left && right) || (left && !right))
            return false;

        int res = true;
        res &= (left->val == right->val);
        res &= isSymmetric(left->left, right->right);
        res &= isSymmetric(left->right, right->left);
        return res;
    }
};