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

Node *find_middle(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    printLL(head);
    Node *middle = find_middle(head);
    cout << middle->val << endl;
}