#include <iostream>
#include <vector>
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

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(Node *root, vector<int> &traversal)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            traversal.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node *root, vector<int> &traversal)
{
    if (isLeaf(root))
    {
        traversal.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, traversal);
    if (root->right)
        addLeaves(root->right, traversal);
}

void addRightBoundary(Node *root, vector<int> &traversal)
{
    Node *curr = root->right;
    vector<int> tmp;

    while (curr)
    {
        if (!isLeaf(curr))
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        traversal.push_back(tmp[i]);
    }
}

void boundary_traversal(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    if (!isLeaf(root))
        traversal.push_back(root->data);

    addLeftBoundary(root, traversal);

    addLeaves(root, traversal);

    addRightBoundary(root, traversal);
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

    boundary_traversal(root, traversal);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal[i] << " ";
    }
    cout << endl;
}