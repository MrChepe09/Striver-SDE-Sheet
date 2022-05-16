#include <iostream>
#include <unordered_set>
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

int getDifference(Node *head1, Node *head2);

Node *find_intersection_optimized_better(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;

    while (d1 != d2)
    {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    return d1;
}

Node *find_intersection_optimized(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);
    if (diff < 0)
    {
        while (diff++ != 0)
        {
            head2 = head2->next;
        }
    }
    else
    {
        while (diff-- != 0)
        {
            head1 = head1->next;
        }
    }
    while (head1 != NULL)
    {
        if (head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

Node *find_intersection(Node *head1, Node *head2)
{
    unordered_set<Node *> uset;
    while (head1 != NULL)
    {
        uset.insert(head1);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        if (uset.find(head2) != uset.end())
        {
            return head2;
        }
        head2 = head2->next;
    }
    return NULL;
}

int getDifference(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;
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
    head = push(10, head);
    head = push(7, head);
    head = push(3, head);
    head = push(1, head);
    Node *head1 = head;
    head = head->next->next;
    Node *headSec = NULL;
    headSec = push(10, headSec);
    headSec = push(8, headSec);
    headSec = push(5, headSec);
    headSec = push(4, headSec);
    Node *head2 = headSec;
    headSec->next->next->next->next = head;

    printLL(head1);
    printLL(head2);
    Node *res = find_intersection_optimized_better(head1, head2);
    cout << res->val << endl;
}