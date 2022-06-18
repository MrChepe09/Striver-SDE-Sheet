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

int find_diameter(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = find_diameter(root->left, diameter);
    int rh = find_diameter(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->left->left = newNode(5);
    root->right->left->left->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->right->right->left->left = newNode(9);
    // root->right->right = newNode(7);
    // root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    int diameter = 0;
    find_diameter(root, diameter);
    cout << diameter << endl;
}