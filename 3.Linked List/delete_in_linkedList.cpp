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
Node *deleteNode(Node *head, int pos)
{
    if (pos == 1)
    {
        Node *curr = head->next;
        delete head;
        return curr;
    }
    Node *curr = head, *prev = NULL;
    for (int i = 1; i < pos && curr != NULL; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr)
    {
        prev->next = curr->next;
        delete curr;
    }
    return head;
}
int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    Node *head = NULL;
    head = create(arr); // creation of linked list

    cout << "Before deleting : ";
    display(head);

    cout << endl;
    cout << "After deleting ";
    deleteNode(head, 3);
    display(head);

    return 0;
}