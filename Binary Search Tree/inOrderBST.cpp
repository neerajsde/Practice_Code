#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Create BST using inorder binary tree list
Node *CreateinOrderBST(int inorder[], int start, int end)
{
    // base case
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);
    // left
    root->left = CreateinOrderBST(inorder, start, mid - 1);
    root->right = CreateinOrderBST(inorder, mid + 1, end);
    return root;
}

// Level Order Traversal
void LevelOrderTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (!front)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    cout << endl;
}

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70}; // must sorted
    int size = sizeof(inorder) / sizeof(int);
    int start = 0, end = size - 1;
    Node *root = CreateinOrderBST(inorder, start, end);
    LevelOrderTraversal(root);
    return 0;
}