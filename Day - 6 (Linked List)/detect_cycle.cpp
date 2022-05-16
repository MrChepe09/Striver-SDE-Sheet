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

bool detect_cycle(Node *head)
{
    if (head == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
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

void createCycle(Node *head, int a, int b)
{
    int cnta = 0, cntb = 0;
    Node *p1 = head, *p2 = head;
    while (cnta != a || cntb != b)
    {
        if (cnta != a)
            p1 = p1->next, ++cnta;
        if (cntb != b)
            p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

int main()
{
    Node *head = NULL;
    head = push(10, head);
    head = push(7, head);
    head = push(3, head);
    head = push(5, head);
    head = push(4, head);
    head = push(1, head);
    createCycle(head, 1, 5);
    // printLL(head);
    bool res = detect_cycle(head);
    cout << res << endl;
}