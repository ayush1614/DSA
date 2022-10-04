// EFFICIENT METHOD   | FLOYD'S LOOP DETECTION METHOD

/*Algo:- in this we mantain two pointers slow and fast ,  slow moves one position ahead and fast moves two positions ahead 
if they matches , loop exits otherwise not */
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

bool detectloop(Node *head)
{
    Node *slow = head, *fast = head; // maintaining fast and slow pointers
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // if slow equals to fast ,  loop exists
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(0);
    head->data = 6;

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

    cout << "Loop exists or not : " << (detectloop(head) ? "true" : "false");
    return 0;
}