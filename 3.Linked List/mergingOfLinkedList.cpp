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

Node *mergeLinkedList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    else if (head2 == NULL)
        return head1;

    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *prev_List1 = head1;
    Node *prev_List2 = head2;
    Node *newHead = NULL;
    ll flag = 1 ; 
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            if (flag) // this is only for new head position
            {
                newHead = head1;
                flag = 0;
                prev_List1 = curr1;
                curr1 = curr1->next;
                continue;
            }

            // appending the nodes from list 1
            prev_List1->next = curr1;
            prev_List1 = curr1;
            curr1 = curr1->next;
        }
        else
        {
            if (flag) // this is only for new head position
            {
                newHead = head2;
                flag = 0;
                prev_List1 = curr2;
                curr2 = curr2->next;
                continue;
            }

            // appending the nodes from list 2
            Node *tmp = curr2;
            prev_List1->next = curr2;

            prev_List1 = curr2;
            curr2 = curr2->next;
        }
    }

    //if list 2 is ended and list 1 is still present 
    if (curr1 != NULL)
        prev_List1->next = curr1;

    //if list 1 is ended and list 2 is still present 
    else
        prev_List1->next = curr2;

    return newHead;
}

int main()
{
    vector<int> arr{1,2,4};
    vector<int> vec{1,3,4};
    Node *head1 = new Node(0), *head2 = new Node(0);

    head1 = create(arr);

    cout << "Linked list 1 : ";
    display(head1);

    cout << endl;

    head2 = create(vec);
    cout << "Linked List 2 : ";
    display(head2);

    cout << endl;
    cout << "Merging of two lists : ";
    Node *newHead = mergeLinkedList(head1, head2);
    display(newHead);

    return 0;
}