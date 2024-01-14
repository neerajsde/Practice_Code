#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Lowest Common Ancestor
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case
    if(!root) return NULL;
    // case 1. p and q both comes in left subtree of a root
    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    // case 2. p and q both comes in right subtree of root node
    if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}
