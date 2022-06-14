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

void morris_inorder(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            traversal.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                traversal.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
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
    morris_inorder(root, traversal);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal[i] << " ";
    }
    cout << endl;
}