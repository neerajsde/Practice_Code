#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}
// Two Sum IV input as a BST LeetCode: 653
bool findTarget(Node *root, int k)
{
    vector<int> nums;
    inOrder(root, nums);
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int total = nums[start] + nums[end];
        if (total == k)
        {
            return true;
        }
        if (total > k)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return false;
}