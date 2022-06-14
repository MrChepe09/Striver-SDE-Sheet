#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
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

void vertical_traversal(Node *root, vector<vector<int>> &traversal)
{
    if (root == NULL)
        return;

    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;

        int x = it.second.first, y = it.second.second;
        nodes[x][y].insert(temp->data);

        if (temp->left)
        {
            q.push({temp->left, {x - 1, y + 1}});
        }

        if (temp->right)
        {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }

    for (auto it : nodes)
    {
        vector<int> col;
        for (auto it2 : it.second)
        {
            col.insert(col.end(), it2.second.begin(), it2.second.end());
        }
        traversal.push_back(col);
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

    vector<vector<int>> traversal;
    vertical_traversal(root, traversal);

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