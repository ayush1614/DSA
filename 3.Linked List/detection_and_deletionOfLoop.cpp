// USING  FLOYD'S LOOP DETECTION METHOD

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void display(Node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// FUNCTION TO DETECT AND DELETE THE LOOP
void detectDeleteLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *slow = head, *fast = head; // MAINTAINING TWO POINTERS
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) // when they meet inside the loop
            break;
    }

    if (slow != fast) // if slow is not equal to fast , no loop present
        return;

    slow = head;
    while (slow->next != fast->next) // checking  the first node of list
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL; // changing links to remove loop
}

int main()
{
    Node *head = new Node(0);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(15);
    head->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next = new Node(20);
    head->next->next->next->next->next->next->next->next = new Node(814);
    head->next->next->next->next->next->next->next->next->next = new Node(19);

    head->next->next->next->next->next->next->next->next->next->next = head->next->next->next->next; // making a loop

    detectDeleteLoop(head);
    display(head);
    return 0;
}