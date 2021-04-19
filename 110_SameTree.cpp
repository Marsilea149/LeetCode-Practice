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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool res = true;
        if (p == nullptr && q == nullptr)
            return true;
        else if (p != nullptr && q != nullptr)
        {
            if (p->val == q->val)
            {
                res &= true;
                res &= isSameTree(p->left, q->left);
                res &= isSameTree(p->right, q->right);
                return res;
            }
            else
            {
                return false;
            }
        }
        else
            return false;
    }
};