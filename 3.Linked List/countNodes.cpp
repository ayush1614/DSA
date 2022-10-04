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

int countNodes(Node *head)
{
    if(head==NULL)
    return 0 ; 

    return countNodes(head->next) + 1 ; 
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node(0);

    head = create(arr);

    cout<<countNodes(head) ; 
    return 0;
}