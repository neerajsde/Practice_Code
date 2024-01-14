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

// Delete a Node From BST
Node *DeleteNodeBST(Node *root, int target)
{
    if (!root)
        return NULL;
    if (root->data == target)
    {
        // target mil gaya ab delete karna hai
        if (!root->left && !root->right)
        {
            // leaf Node case
            delete root;
            return NULL;
        }
        else if (!root->left && root->right)
        {
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else if (root->left && !root->right)
        {
            Node *childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        else
        {
            Node *maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = DeleteNodeBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        // left me chalo
        root->left = DeleteNodeBST(root->left, target);
    }
    else
    {
        // right me chalo
        root->right = DeleteNodeBST(root->right, target);
    }
    return root;
}

int main()
{
    vector<int> arr = {50, 30, 60, 70, 20, 25, 55, 40, 80, 10};
    Node *root = createTree(arr);
    // levelOrderPrinting(root);
    root = insertintoBST(root, 5); // insert into BST
    cout << "Lavel Order Traversal in BST: " << endl;
    levelOrderPrinting(root);

    int t;
    cout << "Enter Target: ";
    cin >> t;
    while (t != -1)
    {
        root = DeleteNodeBST(root, t);
        cout << "Lavel Order Traversal in BST: " << endl;
        levelOrderPrinting(root);
        cout << "Enter Target: ";
        cin >> t;
    }
    return 0;
}