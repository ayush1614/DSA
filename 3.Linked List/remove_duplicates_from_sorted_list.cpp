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

// remove duplicates in sorted list
void removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head->next, *prev = head;
    while (curr != NULL)
    {
        if (curr->data == prev->data)
        {
            Node *tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete tmp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1,1,1,1,1,1,1,1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 6, 9, 9};
    Node *head = NULL;
    head = create(arr);

    cout << "Before removing the duplicates : ";
    display(head);

    cout<<endl;
    cout << "After removing the duplicates : ";
    removeDuplicates(head) ; 
    display(head);
    return 0;
}
