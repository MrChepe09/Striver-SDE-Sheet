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

bool findPath(Node *root, vector<int> &path, int target)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == target)
        return true;

    if (findPath(root->left, path, target) || findPath(root->right, path, target))
        return true;

    path.pop_back();
    return false;
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

    vector<int> path;
    int target;
    cin >> target;
    findPath(root, path, target);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}