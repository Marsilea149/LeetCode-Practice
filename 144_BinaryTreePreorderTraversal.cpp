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
#include <vector>
#include <iostream>
class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(TreeNode *node, std::vector<int> &ans)
    {
        if (node == nullptr)
            return;
        ans.push_back(node->val);
        traversal(node->left, ans);
        traversal(node->right, ans);
        std::cout << "node : " << node->val;
    }
};

int main()
{
    Solution::TreeNode *leftTree;
    leftTree->val = 2;
    leftTree->left->val = 4;
    leftTree->right->val = 5;

    Solution::TreeNode *rightTree;
    leftTree->val = 3;
    leftTree->left = nullptr;
    leftTree->right->val = 6;

    Solution::TreeNode in;
    in.val = 1;
    in.left = leftTree;
    in.right = rightTree;
    Solution::TreeNode *inPtr = &in;

    std::vector<int> preorderedTree = in.Solution::preorderTraversal(inPtr);

    return 0;
}

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        std::vector<int> res;
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *cur = s.top();
            res.push_back(cur->val);
            s.pop();

            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
        return res;
    }
};