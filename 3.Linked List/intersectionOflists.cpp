/* method 1: Time:-  O(m+n) , Space :- O(m) , whereas m , n are size of list1, list2
In this we use the hashing method and stores the first length and then traversing the another list , if any match found we get that
node and if not then their is no intersection .

Method 2 : traversing the larger list from abs(len1-len2) positions ahead , if we get match then intersection present otherwise not

Another methods :-
Naive method :- using two  loops , check any node is matching or not
By changing the structure of linked list

*/

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

// method 1 :- using the hashing technique
Node *hashingTechnique(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;

    unordered_map<Node *, int> ump;
    Node *curr = head1;
    while (curr != NULL)
    {
        ump[curr]++;
        curr = curr->next;
    }
    curr = head2;
    while (curr != NULL)
    {
        if (ump[curr] > 0)
            return curr;

        curr = curr->next;
    }
    return NULL;
}

// method 2  : Using the  node count method
Node *intersection(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    int len1 = 0, len2 = 0;
    Node *curr = head1;
    while (curr != NULL)
    {
        len1++;
        curr = curr->next;
    }

    curr = head2;
    while (curr != NULL)
    {
        len2++;
        curr = curr->next;
    }
    int diff = len1 - len2;
    Node *curr2;
    if (diff >= 0)
        curr = head1, curr2 = head2;

    else
        curr = head2, curr2 = head1;

    diff = abs(diff);
    while (diff--)
        curr = curr->next;

    int d1 = curr->data, d2 = curr2->data;
    while (curr != NULL && curr2 != NULL)
    {
        if (curr == curr2)
            return curr;

        curr = curr->next;
        curr2 = curr2->next;
        // d1 = curr->data ;
        // d2 =curr2->data ;
    }
    return NULL;
}

int main()
{
    vector<int> arr{7, 8, 9, 5, 3, 10, 11, 12, 2, 6, 17};
    Node *head1 = create(arr);

    Node *head2 = new Node(50);
    head2->next = new Node(52);
    head2->next->next = new Node(53);
    head2->next->next->next = head1->next->next->next->next->next->next->next;

    cout << "Linked list1 : ";
    display(head1);
    cout << "\nLinked list1 : ";
    display(head2);

    cout << "\nIntersection1 : ";
    Node *res1 = (hashingTechnique(head1, head2));
    cout << res1;
    cout << "\nIntersection : ";
    Node *res2 = (intersection(head1, head2));
    cout << res2;
}