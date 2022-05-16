#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *bottom;
    Node(int v)
    {
        this->val = v;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a && b)
    {
        if (a->val < b->val)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

Node *flatten_list(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flatten_list(head->next);

    head = mergeTwoLists(head, head->next);

    return head;
}

Node *push_next(int item, Node *head)
{
    Node *temp = new Node(item);
    temp->next = head;
    head = temp;
    return head;
}

Node *push_bottom(int item, Node *head)
{
    Node *temp = new Node(item);
    head->bottom = temp;
    head = head->bottom;
    return head;
}

void printOriginal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        Node *bot = temp->bottom;
        while (bot != NULL)
        {
            cout << bot->val << " -> ";
            bot = bot->bottom;
        }
        temp = temp->next;
    }
    cout << temp->val << endl;
}

void printFlat(Node *head)
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
    head = push_next(28, head);
    Node *head2 = head;
    head2 = push_bottom(35, head2);
    head2 = push_bottom(40, head2);
    head2 = push_bottom(45, head2);
    head = push_next(19, head);
    head2 = head;
    head2 = push_bottom(22, head2);
    head2 = push_bottom(50, head2);
    head = push_next(10, head);
    head2 = head;
    head2 = push_bottom(20, head2);
    head = push_next(5, head);
    head2 = head;
    head2 = push_bottom(7, head2);
    head2 = push_bottom(8, head2);
    head2 = push_bottom(10, head2);
    // printOriginal(head);
    Node *res = flatten_list(head);
    printFlat(res);
}