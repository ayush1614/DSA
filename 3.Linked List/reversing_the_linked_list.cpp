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
// creation of a linked list
Node *create(vector<int> vec)
{
    int n = vec.size();
    if (n == 0)
        return NULL;
    Node *curr, *head = new Node(vec[0]);
    curr = head;
    for (auto i = 1; i < n; i++)
    {
        Node *tmp = new Node(vec[i]);
        curr->next = tmp;
        curr = curr->next;
    }
    return head;
}

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

/// REVERSINNG THE LINKED LIST IN ITERATIVE WAY
Node *Ireverse(Node *head)
{
    if (!head || head->next == NULL)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}

// REVERSING THE LINKED LIST IN RECURSIVE WAY
Node *Rreversal1(Node *head) // keep one element and reverse the rest of the list
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = Rreversal1(head->next); // keep 1st node and pass rest of the list

    head->next->next = head; // reversing the list order

    head->next = NULL;

    return rest; // returning the head
}

// same as of iterative  reversal
Node *Rreversal2(Node *curr, Node *prev) // reversing the n-1 items and append the nth item which is also the head of linked list 
{
    if (curr == NULL)
        return nullptr;

    Node *nxt = curr->next;
    curr->next = prev;
    return Rreversal2(nxt, prev); //moving forward
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};

    Node *head = new Node(0);

    head = create(arr); // creation of linked list

    head = Ireverse(head); // iterative reversal of linked list

    display(head); // printing the list

    head = Rreversal1(head);
    cout << endl;
    display(head);
    return 0;
}