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
void removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head->next, *prev = head;
    unordered_map<int,int>ump ;
    ump[head->data]++;
    while (curr != NULL)
    {
        if (ump[curr->data]>0)
        {
            ump[curr->data]++;
            Node *tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete tmp;
        }
        else
        {
            ump[curr->data]++ ; 
            prev = curr;
            curr = curr->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{10, 1, 3, 4, 68, 6, 1, 8, 9, 31, 10, 8, 6, 31, 31, 6, 7,  1, 6, 75,10};
    Node *head = NULL;
    head = create(arr);

    cout << "Before removing the duplicates : ";
    display(head);

    cout << endl;
    cout << "After removing the duplicates : ";
    removeDuplicates(head);
    display(head);
    return 0;
}
