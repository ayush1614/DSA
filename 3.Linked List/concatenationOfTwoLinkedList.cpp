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

Node *concatenate(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    Node *curr = head1;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = head2;
    return head1;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> vec{6, 7, 8, 9, 10};
    Node *head1 = new Node(0), *head2 = new Node(0);

    head1 = create(arr);

    cout << "Linked list 1 : ";
    display(head1);

    cout << endl;

    head2 = create(vec);
    cout << "Linked List 2 : ";
    display(head2);

    cout << endl;
    cout << "Concatenation of two lists : ";
    Node *newHead = concatenate(head1, head2);
    display(newHead);

    return 0;
}