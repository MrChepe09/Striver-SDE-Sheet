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

Node *remove_Nth(Node *head, int n)
{
    Node *start = new Node(-1);
    start->next = head;
    Node *slow = start, *fast = start;
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
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
    int n;
    cin >> n;
    Node *head = NULL;
    head = push(5, head);
    head = push(3, head);
    head = push(1, head);
    head = push(4, head);
    head = push(6, head);
    head = push(7, head);
    head = push(8, head);
    head = push(9, head);
    printLL(head);
    head = remove_Nth(head, n);
    printLL(head);
}