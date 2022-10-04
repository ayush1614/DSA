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

// iterative way to get the sum 
int ItSum(Node *head)
{
    if (head == NULL)
        return 0;

    int sm = 0;
    while (head != NULL)
    {
        sm += head->data ; 
        head = head->next ; 
    }
    return sm ; 
}

//recursive way to get  the sum
int RecSum(Node *head)
{
    if(head==NULL)
    return 0 ; 

    return head->data + RecSum(head->next) ; 
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};

    Node *head = new Node(0);

    head = create(arr); // creation of linked list

    cout << "Iterative manner : " << ItSum(head);
    cout << endl;
    cout << "Recursive manner sum : " << RecSum(head);
}