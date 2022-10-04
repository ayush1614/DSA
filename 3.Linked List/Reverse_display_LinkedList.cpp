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

//recusrsive method to display reverse of linked list 
void Rreverse(Node * head)
{
    if(head==NULL)
    return ;

    Rreverse(head->next) ; 
    cout<<head->data<<" ";
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11};

    Node *head = new Node(0);

    head = create(arr);

    Rreverse(head) ; 
    return 0;
}