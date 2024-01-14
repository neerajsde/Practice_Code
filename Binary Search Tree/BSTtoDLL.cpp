#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL){};
};

Node *createBST(int inorder[], int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);
    root->left = createBST(inorder, s, mid - 1);
    root->right = createBST(inorder, mid + 1, e);
    return root;
}
// printing BST
void LevelTraversalPrint(Node *root)
{
    if (!root)
    {
        cout << "BST not Exist" << endl;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

// Convert BST into Doubly Linked List
void convertBstToDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;
    // R -> go right
    convertBstToDLL(root->right, head);
    // N -> Processing
    root->right = head;
    if (head)
    {
        head->left = root;
    }
    head = root;
    // L -> go left
    convertBstToDLL(root->left, head);
}
// Printing DLL
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(inorder) / sizeof(int);
    Node *root = createBST(inorder, 0, size - 1);
    cout << "Printing BST: " << endl;
    LevelTraversalPrint(root);
    Node *head = NULL;
    convertBstToDLL(root, head);
    cout << "Printing Linked List: ";
    print(head);
    return 0;
}