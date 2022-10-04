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
Node *lastTofront(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head->next, *prev = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = head;
    return curr;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{10, 1, 3, 4, 68, 6};
    Node *head = NULL;
    head = create(arr);

    cout << "Before removing the duplicates : ";
    display(head);

    cout << endl;
    cout << "After appending the last node to front : ";
    head = lastTofront(head);
    display(head);
    return 0;
}
