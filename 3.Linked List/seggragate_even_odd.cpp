// METHOD 1 : THIS IS  NAIVE METHOD IN WHICH WE STORE THE EVEN ADDRESS AND THEN TRAVERSE THE LINKED LIST AGAIN AND AGAIN
// THIS REQUIRES O(n) TIME .

// M2 :- separates the node , but it generally disrupts the order
// M3:-  make even and odd list separately , and atlast point even list last node to odd list starting node
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

// method 2 :THIS METHOD GENERALLY SEPARATED THE EVEN AND ODD NODES ,  BUT IT DISRUPTS THE ORDER OF THE LIST
void evenOdd2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head, *next = head->next;
    int curr_data = curr->data, next_data = next->data;
    while (next != NULL)
    {
        if (curr->data % 2 == 0)
        {
            curr = next;
            next = next->next;
        }
        else
        {
            if (next->data % 2 == 0)
            {
                swap(curr->data, next->data);
                curr = curr->next;
                next = next->next;
            }
            else
                next = next->next;
        }
    }
}

// METHOD 3 : - Time-> O(n)

Node *evenOdd3(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *evenHead = NULL, *oddHead = NULL, *curr_even = NULL, *curr_odd = NULL, *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0) // for even numbers
        {
            if (evenHead == NULL) // for even head
                evenHead = curr_even = curr;
            else
                curr_even->next = curr, curr_even = curr_even->next;
        }
        else // for odd numbers
        {
            if (oddHead == NULL) // for odd head
                oddHead = curr_odd = curr;
            else
                curr_odd->next = curr, curr_odd = curr_odd->next;
        }
        curr = curr->next;
    }

    if (evenHead == NULL || oddHead == NULL)    // if anyone of them is null , then new head is simply the old head
        return head;

    curr_even->next = oddHead;      //point even last position to odd head 
    curr_odd->next = NULL;      //making odd ending to NULL
    return evenHead;
}
int main()
{
    vector<int> arr{7, 8, 9, 5, 3, 10, 11, 12, 2, 6, 17};
    Node *head = create(arr);

    cout << "Linked list : ";
    display(head);

    cout << "\nAfter seggregating : ";
    head = evenOdd3(head);
    display(head);
}