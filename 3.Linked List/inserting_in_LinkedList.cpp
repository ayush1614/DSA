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

//insert the node at the begining
Node *beginInsert(Node *head, int n)
{
    Node *curr = new Node(n);
    if (head == NULL)
        return curr;

    curr->next = head;
    head = curr;
    return head;
}

//isnert the node at the end 
Node *lastInsert(Node *head, int n)
{
    Node *curr = new Node(n);
    if (head == NULL)
        return curr;

    Node *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = curr;
    return head;
}

//insert the node at the given position
Node *posInsert(Node *head, int n, int pos)
{
    Node *curr = new Node(n);
    if (head == NULL)
        return curr;

    Node *pp = head;
    for (int i = 1; i < pos; i++)
    {
        pp = pp->next;
    }
    curr->next = pp->next;
    pp->next = curr;

    return head;
}

//This function is made for all the types of insertions i.e. beginInsert , lastInsert and given position insert
Node *insert(Node *head, int pos, int n)
{
    Node *tmp = new Node(n);
    if (pos == 0)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }
    else if (pos > 0)
    {
        Node *curr = head;
        for (int i = 0; i < pos - 1 && curr != NULL; i++)
            curr = curr->next;

        if (curr != NULL)
            tmp->next = curr->next;
        curr->next = tmp;
    }
    return head;
}
int main()
{
    vector<int> arr{100, 2000, 3, 4, 5};

    Node *head = NULL;

    head = create(arr); // creation of linked list

    head = beginInsert(head, 50);
    cout << "Insert at beginning : ";
    display(head);

    cout << endl;

    head = lastInsert(head, 0);
    cout << "Insert at last : ";
    display(head);

    posInsert(head, 20, 3);
    cout << endl
         << "Insert at a given position : ";
    display(head);

    cout << endl;
    head = insert(head, 1, -1);
    cout << "Insert function ";
    display(head);
    return 0;
}