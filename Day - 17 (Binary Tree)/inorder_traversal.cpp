#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *item = new Node();
    item->data = data;
    item->left = NULL;
    item->right = NULL;
    return item;
}

void inorder_iterative(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    Node *curr = root;
    stack<Node *> s;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top();
            s.pop();
            traversal.push_back(curr->data);
            curr = curr->right;
        }
    }
}

void inorder_recursive(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    inorder_recursive(root->left, traversal);
    traversal.push_back(root->data);
    inorder_recursive(root->right, traversal);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> traversal;
    inorder_iterative(root, traversal);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal[i] << " ";
    }
    cout << endl;
}