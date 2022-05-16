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

int lengthLL(Node *head)
{
    int len = 0;
    while (head != NULL)
        ++len, head = head->next;
    return len;
}

Node *reverseLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int len = lengthLL(head);
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *pre = dummy, *curr, *next;

    while (len >= k)
    {
        curr = pre->next;
        next = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = curr->next;
        }
        pre = curr;
        len -= k;
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
    Node *head = NULL;
    head = push(10, head);
    head = push(7, head);
    head = push(3, head);
    head = push(5, head);
    head = push(4, head);
    head = push(1, head);
    printLL(head);
    int k = 2;
    Node *resHead = reverseLL(head, k);
    printLL(resHead);
}