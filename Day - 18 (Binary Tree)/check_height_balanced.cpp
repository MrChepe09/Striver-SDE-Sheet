#include <iostream>
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

int height_balance(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height_balance(root->left);
    if (lh == -1)
        return -1;

    int rh = height_balance(root->right);
    if (rh == -1)
        return -1;

    if (std::abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
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
    int height = height_balance(root);

    cout << (height == -1 ? false : true) << endl;
}