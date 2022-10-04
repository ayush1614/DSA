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

Node *insert(Node *head, int n)
{
    Node *tmp = new Node(n);
    Node *curr, *prev;
    curr = head, prev = NULL;

    while (curr != NULL)
    {
        if (curr->data >= n)
            break;

        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) // if we insert at the begining
    {
        tmp->next = curr;
        head = tmp;
    }
    else        // if we insert at any other position
    {
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return head;
}

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    Node *head = NULL;
    head = create(arr); // creation of linked list

    cout << "Before insertion : ";
    display(head);

    cout << endl
         << "After insertion : ";
    head = insert(head, 35);
    display(head);
    cout << endl
         << "After insertion : ";
    head = insert(head, 0);
    display(head);

    return 0;
}