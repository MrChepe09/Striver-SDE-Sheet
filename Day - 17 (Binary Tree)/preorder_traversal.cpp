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

void preorder_iterative(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        traversal.push_back(curr->data);

        if (curr->right)
            s.push(curr->right);

        if (curr->left)
            s.push(curr->left);
    }
}

void preorder_recursive(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    traversal.push_back(root->data);
    preorder_recursive(root->left, traversal);
    preorder_recursive(root->right, traversal);
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
    preorder_iterative(root, traversal);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal[i] << " ";
    }
    cout << endl;
}