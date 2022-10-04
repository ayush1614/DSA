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

// iterative way to get the maximum
int ItMax(Node *head)
{
    if (head == NULL)
        return -1;

    int mx = INT_MIN;
    while (head != NULL)
    {
        mx = max(mx, head->data);
        head = head->next;
    }

    return mx ; 
}

//recursive way to get the maximum
int recMax(Node * head)
{
    if(head==NULL)
    return -1 ; 

    return max(head->data , recMax(head->next)) ; 
}


int main()
{
    vector<int> arr{100, 2000, 3, 4, 5};

    Node *head = new Node(0);

    head = create(arr); // creation of linked list

    cout << "Iterative manner : " << ItMax(head);
    cout << endl;
    cout << "Recursive manner  : " << recMax(head);
}