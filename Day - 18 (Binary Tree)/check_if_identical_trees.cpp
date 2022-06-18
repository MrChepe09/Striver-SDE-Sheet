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

bool identical_trees(Node *rootA, Node *rootB)
{
    if (rootA == NULL && rootB == NULL)
        return true;
    else if (rootA == NULL || rootB == NULL)
        return false;

    return ((rootA->data == rootB->data) && identical_trees(rootA->left, rootB->left) && (identical_trees(rootA->right, rootB->right)));
}

int main()
{
    // Tree 1
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

    // Tree 2
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->left->right->left = newNode(8);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1->right->right->left = newNode(9);
    root1->right->right->right = newNode(10);

    bool identical = identical_trees(root, root1);
    cout << identical << endl;
}
