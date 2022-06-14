#include <iostream>
#include <vector>
#include <stack>
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

void all_traversals(Node *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    if (root == NULL)
        return;
    stack<pair<Node *, int>> st;
    Node *curr = root;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            postorder.push_back(it.first->data);
        }
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> preorder, inorder, postorder;
    all_traversals(root, preorder, inorder, postorder);
    cout << "Preorder: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;
    cout << "Inorder: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
    cout << "Postorder: ";
    for (int i = 0; i < postorder.size(); i++)
    {
        cout << postorder[i] << " ";
    }
    cout << endl;
}