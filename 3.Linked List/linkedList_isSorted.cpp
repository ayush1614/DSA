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
bool isSorted(Node *head)
{
    int mx = INT_MIN;
    while (head != NULL)
    {
        if (mx > head->data)
            return false;

        mx = head->data;
        head = head->next;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1030, 5, 88, 1, 3, 20, 7, 90, 0, 2};
    Node *head = NULL;
    head = create(arr);

    cout << "Sorted or not : " << isSorted(head);
    return 0;
}
