#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Validate binary search tree
bool slove(TreeNode *root, long long int lowerbound, long long int upperbound)
{
    if (root == NULL)
        return true;

    bool cond1 = (root->val > lowerbound);
    bool cond2 = (root->val < upperbound);
    bool leftAns = slove(root->left, lowerbound, root->val);
    bool rightAns = slove(root->right, root->val, upperbound);
    return (cond1 && cond2 && leftAns && rightAns);
}
bool isValidBST(TreeNode *root)
{
    long long int lowerbound = -2147483658;
    long long int upperbound = 2147483657;
    return slove(root, lowerbound, upperbound);
}
