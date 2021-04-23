/** Difficulty: 6/10 
 * BST think about sort the nodes increasingly with "InOrder" algorithm
 * 
 * Time complexity: n
 * Space complexity: n
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
    int getMinimumDifference(TreeNode *root)
    {
        // sort the nodes of the BST increasingly
        std::vector<int> sorted;
        inOrder(root, sorted);
        // store the difference of each neighbor in the sorted vector
        int diff = sorted.back();
        for (int i = 0; i < sorted.size() - 1; ++i)
        {
            if ((sorted[i + 1] - sorted[i]) < diff)
                diff = sorted[i + 1] - sorted[i];
        }
        return diff;
    }

    void inOrder(TreeNode *root, std::vector<int> &sorted)
    {
        if (!root)
            return;

        inOrder(root->left, sorted);
        sorted.push_back(root->val);
        inOrder(root->right, sorted);
    }
};