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

Node *rotateLL_optimized(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    Node *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        ++length;
        temp = temp->next;
    }

    temp->next = head;
    k = k % length;
    int end = length - k;
    while (end--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

Node *rotateLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
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
    head = push(2, head);
    head = push(3, head);
    head = push(4, head);
    head = push(5, head);
    head = push(6, head);
    head = push(7, head);
    head = push(8, head);
    head = push(9, head);
    int k = 5;
    printLL(head);
    Node *res = rotateLL_optimized(head, k);
    printLL(res);
}