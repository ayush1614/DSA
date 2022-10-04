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

int ItSearch(Node *head, int n)
{
    if (head == NULL)
        return -1;

    int idx = 1;
    while (head != NULL)
    {
        if (head->data == n)
        {
            return idx;
        }

        head = head->next;
        idx++;
    }
    return -1;
}

ll recSearch(Node *head, int n)
{
    if (head == NULL)
        return -1;

    if(head->data==n)
    return 1  ;

    int res =   recSearch(head->next,  n);
    if(res==-1)
    return -1;

    else
    return res+1  ;  
}
int main()
{
    vector<int> arr{100, 2000, 3, 4, 5};

    Node *head = new Node(0);

    head = create(arr); // creation of linked list

    cout << "Iterative manner : " << ItSearch(head, 3);
    cout << endl;
    cout << "Recursive manner  : " << recSearch(head,3);
}