#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int n)
    {
        this->val = n;
        next = NULL;
    }
};

class cmp
{
public:
    bool operator()(struct Node *n1, struct Node *n2)
    {
        return n1->val > n2->val;
    }
};

Node *merge_k_sorted_list(int n, vector<Node *> arr, int k)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    priority_queue<Node *, vector<Node *>, cmp> pq;

    for (int i = 0; i < n; i++)
    {
        if (arr[i])
            pq.push(arr[i]);
    }

    if (pq.empty())
        return NULL;

    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        temp->next = curr;
        temp = temp->next;

        if (curr->next)
            pq.push(curr->next);
    }

    return dummy->next;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << temp->val << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<Node *> arr(n);
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node *head = merge_k_sorted_list(n, arr, k);
    printLL(head);
}