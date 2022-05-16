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

Node *reverseLL(Node *head)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool is_pallindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseLL(slow->next);
    slow = slow->next;
    // printLL(head);
    Node *dummy = head;
    while (slow != NULL)
    {
        if (dummy->val != slow->val)
            return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
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
    head = push(1, head);
    head = push(4, head);
    head = push(5, head);
    head = push(5, head);
    head = push(4, head);
    head = push(1, head);
    printLL(head);
    bool res = is_pallindrome(head);
    cout << res << endl;
}