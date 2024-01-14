#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
    ~Node()
    {
        delete left;
        delete right;
    }
};
// inserting element into Binary Search Tree
Node *insertintoBST(Node *root, int element)
{
    if (root == NULL)
    {
        root = new Node(element);
        return root;
    }
    if (element > root->data)
    {
        root->right = insertintoBST(root->right, element);
    }
    else
    {
        root->left = insertintoBST(root->left, element);
    }
    return root;
}
// Create Binary Search Tree
Node *createTree(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    Node *root = NULL;
    while (index < n)
    {
        root = insertintoBST(root, nums[index]);
        index++;
    }
    return root;
}

// Level Ordering Traversal
void levelOrderPrinting(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
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

// PreOrder Traversal
void PreOrderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
// InOrder Traversal
void InOrderTraversal(Node *root)
{
    if (!root)
        return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
// Post Order Traversal
void PostOrderTraversal(Node *root)
{
    if (!root)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// find maximum value into BST
Node *maxValue(Node *root)
{
    if (!root)
        return root;
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}
// find minimum value into BST
Node *minValue(Node *root)
{
    if (!root)
        return root;
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

// Binary Searching into Tree algorithm
bool SearchingElement(Node *root, int &target)
{
    if (!root)
        return false;
    if (root->data == target)
    {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if (root->data > target)
    {
        leftAns = SearchingElement(root->left, target);
    }
    else
    {
        rightAns = SearchingElement(root->right, target);
    }
    return leftAns || rightAns;
}

int main()
{
    vector<int> arr = {50, 30, 60, 70, 20, 25, 55, 40, 80, 10};
    Node *root = createTree(arr);
    // levelOrderPrinting(root);
    root = insertintoBST(root, 5); // insert into BST
    cout << "Lavel Order Traversal in BST: " << endl;
    levelOrderPrinting(root);
    cout << "PreOrder Traversal: ";
    PreOrderTraversal(root);
    cout << endl;
    cout << "InOrder Traversal: ";
    InOrderTraversal(root); // always sorted
    cout << endl;
    cout << "PostOrder Traversal: ";
    PostOrderTraversal(root);
    cout << endl
         << endl;
    cout << "Max Value of Node into BST: " << maxValue(root)->data << endl;
    cout << "Min Value of Node into BST: " << minValue(root)->data << endl;

    // Binary searching
    int target;
    cout << "Enter Traget: ";
    cin >> target;
    while (target != -1)
    {
        if (SearchingElement(root, target))
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not found." << endl;
        }
        cout << "Enter Target: ";
        cin >> target;
    }
    return 0;
}