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

void left_recursion(Node *root, int level, vector<int> &left)
{
    if (root == NULL)
        return;

    if (left.size() == level)
        left.push_back(root->data);
    left_recursion(root->left, level + 1, left);
    left_recursion(root->right, level + 1, left);
}

void right_recursion(Node *root, int level, vector<int> &right)
{
    if (root == NULL)
        return;

    if (right.size() == level)
        right.push_back(root->data);
    right_recursion(root->right, level + 1, right);
    right_recursion(root->left, level + 1, right);
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

    vector<int> left, right;
    left_recursion(root, 0, left);
    right_recursion(root, 0, right);
    cout << "Left: ";
    for (int i = 0; i < left.size(); i++)
    {
        cout << left[i] << " ";
    }
    cout << endl;
    cout << "Right: ";
    for (int i = 0; i < right.size(); i++)
    {
        cout << right[i] << " ";
    }
    cout << endl;
}