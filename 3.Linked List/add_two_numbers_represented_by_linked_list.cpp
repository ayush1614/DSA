#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
public:
    ll data;
    Node *next;

    Node(ll x)
    {
        data = x;
        next = NULL;
    }
};
// creation of a linked list
Node *create(vector<ll> vec)
{
    ll n = vec.size();
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

ll add(Node *head)
{
    if (head == NULL)
        return 0;

    ll num = 0;
    string str = "";
    while (head != NULL)
    {
        str.append(to_string(head->data));
        head = head->next;
    }
    for (ll i = 0; i < str.size(); i++)
        num = num * 10 + (str[i] - '0');

    return num;
}

Node *addListSum(ll num) 
{
    Node *prev = NULL ; 
    while(num)
    {
        Node *curr = new Node(num%10);
        curr->next = prev ;
        prev = curr ;
        num/=10;
    }
    return prev ; 
}
int main(int argc, char const *argv[])
{
    vector<ll> arr{10, 1, 3, 31};
    vector<ll> vec{4, 68, 6, 1, 8, 9};
    Node *head1 = create(arr);
    Node *head2 = create(vec);

    cout << "Linked List 1  : ";
    display(head1);
    ll sm1 = add(head1);
    cout <<"\nsm1 "<<sm1<< endl;

    cout << "Linked List 2  : ";
    display(head2);
    ll sm2 = add(head2);
    cout <<"\nsm2 "<<sm2<< endl;

    cout << "After adding new list will be  : ";
    Node *head3 = addListSum(sm1 + sm2);
    display(head3);
    return 0;
}
