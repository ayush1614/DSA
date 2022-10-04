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

// this method require two traversal of linked list | first traversal to count the length of list and second is to reach the middle
void middle(Node *head)
{
    if (head == NULL)
    {
        cout << "head is null ";
        return;
    }
    else
    {
        int len = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 1; i <= len / 2; i++)
            curr = curr->next;

        cout << "data " << curr->data;
    }
}

// using two pointer approach we can find out the middle of the list in one traversal 
void middle1(Node *head)
{
    if (head == NULL)
    {
        cout << "Head is null ";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Data " << head->data;
        return;
    }
    else
    {
        Node *slow, *fast;
        slow = fast = head;

        while(fast!=NULL &&  fast->next!=NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ; 
        }
        cout<<"Data is "<<slow->data ; 
    }
}

int main()
{
    vector<int> arr{1, 12};
    vector<int> vec{-6, 7, 8, 9, 100};
    Node *head = new Node(0);

    head = create(arr);

    cout << "Linked list : ";
    display(head);

    cout << endl;
    middle(head);           //by simple naive approach by counting the length and finding the middle of linked list 

    cout << endl;
    middle1(head);         // using two pointer approach 
}