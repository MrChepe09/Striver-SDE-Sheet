#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int v)
    {
        this->val = v;
        next = NULL;
        random = NULL;
    }
};

Node *copy_LL_random_pointer(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head, *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = temp;
    }

    curr = head;
    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *original = head, *copy = head->next;
    temp = copy;
    while (original && copy)
    {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;

        original = original->next;
        copy = copy->next;
    }
    return temp;
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
        if (temp->random)
        {
            cout << "r " << temp->random->val << " -> ";
        }
        else
        {
            cout << "rnull -> ";
        }
        temp = temp->next;
    }
    cout << temp->val << " -> ";
    if (temp->random)
    {
        cout << "r " << temp->random->val << endl;
    }
    else
    {
        cout << "rnull " << endl;
    }
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
    head->random = head->next->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next;
    head->next->next->next->next->next->random = head->next;
    head->next->next->next->next->next->next->random = head->next;
    head->next->next->next->next->next->next->next->random = head->next;
    // printLL(head);
    Node *res = copy_LL_random_pointer(head);
    printLL(res);
}