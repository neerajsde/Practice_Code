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

// Convert Sorted doubly linked list to BST
Node *convertDLLtoBST(Node *&head, int n)
{
    if (!head || n <= 0)
    {
        return NULL;
    }
    // L
    Node *leftAns = convertDLLtoBST(head, n / 2);
    // N
    Node *node = new Node(head->data);
    node->left = leftAns;
    head = head->right;
    // R
    Node *rightAns = convertDLLtoBST(head, n - n / 2 - 1);
    node->right = rightAns;
    return node;
}

// create doubly linked list
void insertDLL(Node *&head, int val)
{
    if (head == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->right)
        {
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
    }
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

// Printing DLL
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "-> ";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(int);
    Node *head = NULL;
    for (int i = 0; i < size; i++)
    {
        insertDLL(head, arr[i]);
    }
    cout << "Linked List: ";
    print(head);
    Node *root = convertDLLtoBST(head, size);
    cout << "\nLevel Order Traversal: " << endl;
    LevelTraversalPrint(root);
    return 0;
}