#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v)
    {
        this->val = v;
        next = NULL;
    }
};

Node *delete_node(Node *head, int v)
{
    Node *curr = head;
    while (curr->val != v)
    {
        curr = curr->next;
    }
    curr->val = curr->next->val;
    curr->next = curr->next->next;
    return head;
}

Node *push(int item, Node *head)
{
    Node *temp = new Node(item);
    temp->next = head;
    head = temp;
    return head;
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
    Node *head = NULL;
    head = push(5, head);
    head = push(3, head);
    head = push(1, head);
    head = push(4, head);
    head = push(6, head);
    head = push(7, head);
    head = push(8, head);
    head = push(9, head);
    int val;
    cin >> val;
    printLL(head);
    head = delete_node(head, val);
    printLL(head);
}