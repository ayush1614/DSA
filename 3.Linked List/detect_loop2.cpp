// Method 3 : making  a dummy node and pointing all the nodes to the dummy node and if any of the node already pointed the dummy node then their
//  is a loop       || THIS METHOD DISTROYS THE LINKED LIST BUT FINDS OUT WHETHER IT CONTAINS LOOP OR NOT

// METHOD 4 :using the hashing method , if that node node is alredy present in the map then their is a loop, otherwise not a loop

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

// IMPLEMNTATION OF 3RD METHOD  || this mehod destroys the linked list  || O(n) method
bool detectloop1(Node *head)
{
    if (head == NULL)
        return false;

    Node *dummy = new Node(0);
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;

        else if (curr->next == dummy)
            return true;

        Node *tmp = curr->next;
        curr->next = dummy;
        curr = tmp;
    }
    return false;
}

// implementation of 4TH method
bool detectloop2(Node *head) // TIME :- O(n) and O(n) space
{
    if (head == NULL)
        return false;

    unordered_map<Node *, ll> ump;
    Node *curr = head;
    while (curr != NULL)
    {
        if (ump[curr] > 0)
            return true;

        ump[curr]++;
        curr = curr->next;
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

    cout << "Loop exists or not : " << (detectloop2(head) ? "true" : "false");
    return 0;
}