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

Node *add_two_numbers(Node *head1, Node *head2)
{
    int carry = 0;
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while ((head1 != NULL || head2 != NULL) || carry)
    {
        int sum = 0;
        if (head1 != NULL)
        {
            sum += head1->val;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->val;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
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
    head1 = push(1, head1);
    head1 = push(7, head1);
    head1 = push(3, head1);
    head1 = push(1, head1);
    Node *head2 = NULL;
    head2 = push(1, head2);
    head2 = push(8, head2);
    head2 = push(5, head2);
    head2 = push(2, head2);
    head2 = push(1, head2);

    printLL(head1);
    printLL(head2);
    Node *res = add_two_numbers(head1, head2);
    printLL(res);
}