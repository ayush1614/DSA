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

Node *removeOccurences(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *dummy;

    dummy->next = head; // dummmy node points to original head

    Node *prev = dummy; // node which has no duplicate

    Node *curr = head;

    while (curr != NULL)
    {
        // traverse until the curr is null or we gate the different value
        while (curr->next != NULL && prev->next->data == curr->next->data)
            curr = curr->next;

        // if current has unique value
        // i.e current is not updated,
        // Move the prev pointer to
        // next node
        if (prev->next == curr)
            prev = prev->next;

        // when current is updated
        // to the last duplicate
        // value of that segment,
        // make prev the next of current
        else
            prev->next = curr->next;

        curr = curr->next;
    }
    // update the head ;
    head = dummy->next;

    return head;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{1, 1, 1, 4, 4, 40};
    Node *head = NULL;
    head = create(arr);

    cout << "Linked list : ";
    display(head);

    cout << endl;
    cout << "After appending the last node to front : ";
    head = removeOccurences(head);
    display(head);
    return 0;
}
