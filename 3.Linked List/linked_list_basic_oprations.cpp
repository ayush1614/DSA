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

//creation of a linked list 
Node *create(vector<int> vec)
{
    int n = vec.size();
    Node *curr, *head = new Node(vec[0]);
    curr = head;
    for (auto i = 1; i < n; i++)
    {
        Node *tmp = new Node(vec[i]);
        curr->next = tmp;
        curr = curr->next ; 
    }
    return head;
}

//displaying a linked list in iterative  way 
void display(Node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data<<" ";
        head = head->next;
    }
}

void Rdisplay(Node *head)
{
    if(head==NULL)
    return  ; 

    else
    {
        cout<<head->data<<" " ; 
        Rdisplay(head->next) ; 
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node(NULL);

    head = create(arr);

    // display(head);      //iterative display

    Rdisplay(head) ;    // recursive display
    return 0;
}