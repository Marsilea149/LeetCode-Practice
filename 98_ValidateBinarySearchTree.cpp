/**Difficulty: 7/10
 * 
 * Trick: This solution use nullptr to indicate the infinity(- and +), 
 * once their is a non infinity number, the pointer is not nullptr anymore!
 * The recursive call of isValidBST enables the check from left -> right -> root, bottom up
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }

private:
    bool isValidBST(TreeNode *root, int *minVal, int *maxVal)
    {
        if (!root)
            return true;

        if ((minVal && root->val <= *minVal) || (maxVal && root->val >= *maxVal))
            return false;

        return isValidBST(root->left, minVal, &root->val) && isValidBST(root->right, &root->val, maxVal);
    }
};