#include <iostream>
#include <queue>
using namespace std;

// Generic Binary Tree
class Node
{
public:
    int data;
    int children_count;
    Node **children;
    Node(int val)
    {
        this->data = val;
        this->children_count = 0;
        this->children = 0;
    }
};

Node *takeInput()
{
    cout << "Enter root data: ";
    int data;
    cin >> data;
    cout << "Enter Children count for " << data << " node: ";
    int count;
    cin >> count;
    Node *root = new Node(data);
    root->children_count = count;
    root->children = new Node *[count];
    for (int i = 0; i < count; i++)
    {
        root->children[i] = takeInput();
    }
    return root;
}

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
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
            for (int i = 0; i < temp->children_count; i++)
            {
                if (temp->children[i])
                {
                    q.push(temp->children[i]);
                }
            }
        }
    }
}

int main()
{
    Node *root = takeInput();
    cout << "Lavel Order Traversal: ";
    cout << endl;
    levelOrderTraversal(root);
    return 0;
}