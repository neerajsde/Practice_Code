#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL){}
};

int KthSmallest(Node* root, int &k){
    if(!root) return -1;

    // left
    int leftAns = KthSmallest(root->left, k);
    if(leftAns != -1) return leftAns;
    // N
    k--;
    if(k == 0) return root->data;
    // Right
    int RightAns = KthSmallest(root->right, k);
    return RightAns;
}