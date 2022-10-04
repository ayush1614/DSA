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

// this is recursive solution | Takes O(n) time and O(n/k) extra space i.e call stack space
Node *RecgrpReverse(Node *head, int k)
{
    if (head == NULL)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;
    int cnt = 0;

    // reversing the 1st k nodes
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    // cout<<"\ndisplay : ";display(prev);
    if (next != NULL) // if next is not null we pass the rest of the list
    {
        Node *rol = RecgrpReverse(next, k);
        head->next = rol;
    }

    return prev;
}

// takes O(n) time | O(1) extra space | iterative method to grp reverse the list
Node *ItergrpReverse(Node *head, int k)
{
    if (head == NULL)
        return head;

    Node *curr = head, *first_prev = NULL, *next = NULL, *newHead = NULL;
    int flag = 1;
    while (curr != NULL)
    {
        Node *prev = NULL, *first = curr;
        int cnt = 0;
        while (cnt < k && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if (flag)
        {
            flag = 0;
            head = prev;
        }
        else
            first_prev->next = prev;

        first_prev = first;
    }
    return head;
}
int main()
{
    vector<int> arr{-6, 7, 8, 9, 100, 11, 5, 7, 8, 9};
    Node *head = new Node(0);

    head = create(arr);

    cout << "Linked list : ";
    display(head);

    cout << "\nAfter recursive reversing : ";
    head = RecgrpReverse(head, 2);

    display(head);

    cout << "\nAfter iterative reversing : ";
    head = ItergrpReverse(head, 2);

    display(head);
}