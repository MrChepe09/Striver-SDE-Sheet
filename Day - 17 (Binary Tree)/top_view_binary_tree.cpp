#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
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

void bottom_recursion(Node *root, vector<int> &bottom)
{
    if (root == NULL)
        return;

    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *curr = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
            mp[line] = curr->data;

        if (curr->left != NULL)
        {
            q.push({curr->left, line - 1});
        }

        if (curr->right != NULL)
        {
            q.push({curr->right, line + 1});
        }
    }

    for (auto it : mp)
    {
        bottom.push_back(it.second);
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

    vector<int> bottom;
    bottom_recursion(root, bottom);
    cout << "Bottom: ";
    for (int i = 0; i < bottom.size(); i++)
    {
        cout << bottom[i] << " ";
    }
    cout << endl;
}