#include <iostream>
#include <vector>
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

vector<vector<int>> zigzag_traversal(Node *root)
{
    if (root == NULL)
        return {};

    queue<Node *> q;
    vector<vector<int>> nodes;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = curr->data;

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        leftToRight = !leftToRight;
        nodes.push_back(row);
    }
    return nodes;
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

    vector<vector<int>> traversal = zigzag_traversal(root);

    for (int i = 0; i < traversal.size(); i++)
    {
        for (int j = 0; j < traversal[i].size(); j++)
        {
            cout << traversal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}