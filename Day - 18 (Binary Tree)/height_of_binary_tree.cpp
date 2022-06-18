#include <iostream>
#include <queue>
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

// Level order traversal
int find_height_iterative(Node *root)
{
    int level = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        level++;
    }
    return level;
}

// Postorder Traversal
int find_height_recursive(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = find_height_recursive(root->left);
    int rh = find_height_recursive(root->right);

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

    int height = find_height_recursive(root);
    cout << height << endl;
}