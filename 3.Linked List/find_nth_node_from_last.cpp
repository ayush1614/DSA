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

void nthNode(Node *head, int n) // naive method using two loops
{
    if (head == NULL)
    {
        cout << "List is empty ";
        return;
    }
    int len = 0;
    Node *curr = head;
    while (curr != NULL)    //count  the length of linked list 
    {
        len++;
        curr = curr->next;
    }
    if (len >= n)   // if length is less than n 
    {
        curr = head;
        for (int i = 1; i <= len - n; i++)
            curr = curr->next;

        cout << "nth node data is : " << curr->data;
    }
    else
        cout << "Not present in list ";
}

void nthNode1(Node *head, int n) // using two pointers approach
{
    if (head == NULL)
    {
        cout << "head is null ";
        return;
    }

    Node *slow = head, *fast = head;
    while (n--) // moving fast pointer to n positions ahead
    {
        if (fast == NULL) // if n is larger we get the NULL value because we never reach that value
        {
            cout << "out of the list ";
            return;
        }
        fast = fast->next;
    }

    while (fast != NULL) // if position is valid
    {
        slow = slow->next; // moving both pointers with same speed
        fast = fast->next;
    }
    cout << "Data is " << slow->data;
}

int main()
{
    vector<int> arr{1, 12, 5, 99, 6, 3, 5, 65};
    vector<int> vec{-6, 7, 8, 9, 100};
    Node *head = new Node(0);

    head = create(arr);

    cout << "Linked list : ";
    display(head);

    cout << endl;
    nthNode(head, 10); // using naive method i.e. find length of list and traverse upto len - n + 1 th position

    cout << endl;
    nthNode1(head, 9); // using two pointer method

    return 0;
}