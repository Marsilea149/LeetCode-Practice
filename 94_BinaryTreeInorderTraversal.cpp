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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(TreeNode *node, std::vector<int> &ans)
    {
        if (node == nullptr)
        {
            return;
        }

        traversal(node->left, ans);
        ans.push_back(node->val);
        traversal(node->right, ans);
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> res;
        stack<TreeNode *> s;
        TreeNode *curNode = root;
        while (curNode != nullptr || !s.empty())
        {
            while (curNode != nullptr)
            {
                s.push(curNode);
                curNode = curNode->left;
            }
            curNode = s.top();
            res.push_back(curNode->val);
            s.pop();
            curNode = curNode->right;
        }
        return res;
    }
};