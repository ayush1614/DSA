// First methodd is naive method in which we have to hold the list and check all for other nodes have same address as of holding node
// if yes then their is  a loop otherwise not

/*2nd method is making a visited block , if block is visited and we comes it at again then their is a loop else not a loop, this method
changes the structure of list*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // this method requires modification of list |  TIME :- O(n) and modification with some more ectra space for each node

class Node
{
public:
    int data;
    Node *next;
    bool visited; // linked list structure get changed
    Node(int x)
    {
        data = x;
        next = NULL;
        visited = 1;
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

// implementation of second method
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->visited == 0) // if the visited node is again visited then loop is present
            return true;

        curr->visited = 0;
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

    head->next->next->next->next->next->next->next->next->next->next = head->next->next->next->next;        //making a loop

    cout << "Loop exists or not : " << (detectLoop(head) ? "true" : "false");
    return 0;
}