#include <iostream>
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

int max_width(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int curr_size = q.size();
        int curr_min = q.front().second;
        int leftmost, rightmost;

        for (int i = 0; i < curr_size; i++)
        {
            int curr_id = q.front().second - curr_min;
            Node *temp = q.front().first;
            q.pop();
            if (i == 0)
                leftmost = curr_id;
            if (i == curr_size - 1)
                rightmost = curr_id;

            if (temp->left)
                q.push({temp->left, curr_id * 2 + 1});
            if (temp->right)
                q.push({temp->right, curr_id * 2 + 2});
        }

        ans = max(ans, rightmost - leftmost + 1);
    }
    return ans;
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

    int ans = max_width(root);
    cout << ans << endl;
}