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

Node *mergeLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->val > head2->val)
    {
        swap(head1, head2);
    }

    Node *res = head1;
    while (head1 != NULL && head2 != NULL)
    {
        Node *temp = NULL;
        while (head1 != NULL && head1->val <= head2->val)
        {
            temp = head1;
            head1 = head1->next;
        }

        temp->next = head2;
        swap(head1, head2);
    }
    return res;
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
    Node *head1 = NULL;
    head1 = push(10, head1);
    head1 = push(7, head1);
    head1 = push(3, head1);
    // head1 = push(1, head1);
    Node *head2 = NULL;
    head2 = push(10, head2);
    head2 = push(8, head2);
    head2 = push(5, head2);
    head2 = push(2, head2);
    head2 = push(1, head2);

    printLL(head1);
    printLL(head2);
    Node *res = mergeLL(head1, head2);
    printLL(res);
}