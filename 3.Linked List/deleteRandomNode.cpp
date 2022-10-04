/* deleting a random pointer given and we have to delete it , we do it by simply copy the data of
next node in curr node and delete the next node.This works only when the node is other than the
last node , bcuz we don't have next node to copy its data  */

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

// deleting a random pointer
void deleteRandomNode(Node *ptr)
{
    if (ptr == NULL)
        return;

    if (ptr->next != NULL)
    {
        Node *curr = ptr->next;
        ptr->data = curr->data;
        ptr->next = curr->next;
        delete (curr);
    }
    else
        ptr->data = 0;
}

int main()
{
    vector<int> arr{6, 7, 8, 9, 10, 11, 12, 22, 25, 31, 25};
    Node *head = create(arr);

    cout << "Linked list : ";
    display(head);

    Node *tmp = head->next->next; // pointer to delete
    deleteRandomNode(tmp);
    cout << "\nAfter removing specific node ";
    display(head);
}