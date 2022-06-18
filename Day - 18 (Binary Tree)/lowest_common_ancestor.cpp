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

Node *lowest_common_ancestor(Node *root, Node *first, Node *second)
{
    if (root == NULL || root == first || root == second)
        return root;

    Node *left = lowest_common_ancestor(root->left, first, second);
    Node *right = lowest_common_ancestor(root->right, first, second);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
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

    Node *ancestor = lowest_common_ancestor(root, root->left->left, root->left->right->left);

    cout << ancestor->data << endl;
}