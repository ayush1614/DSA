#include <bits/stdc++.h>
using namespace std;
class Node // structure of tree
{

public:
    int data;
    Node *lchild, *rChild;
    Node(int x)
    {
        data = x;
        lchild = rChild = NULL;
    }
};

Node *createTree() // creating a tree using the queue
{
    int dt;
    cout << "Enter the root data(-1 for NULL) : ";
    cin >> dt;
    if (dt == -1)
        return NULL;

    Node *rt = new Node(dt);
    queue<Node *> q; // storing address of Nodes
    q.push(rt);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();

        // left child entry
        int ldt;
        cout << "Enter data for left child(-1 for NULL) of " << tmp->data << " : ";
        cin >> ldt;

        if (ldt != -1)
        {
            Node *lNode = new Node(ldt);
            tmp->lchild = lNode;
            q.push(lNode);
        }

        // right child entry
        int rdt;
        cout << "Enter data for right child(-1 for NULL) of " << tmp->data << " : ";
        cin >> rdt;

        if (rdt != -1)
        {
            Node *rNode = new Node(rdt);
            tmp->rChild = rNode;
            q.push(rNode);
        }
    }
    return rt;
}
// longest path between two nodes
// not necessary to pass from root node
int diameter(Node *head, int &dia)
{
    if (head == NULL)
        return 4;

    int lh = diameter(head->lchild, dia);
    int rh = diameter(head->rChild, dia);

    dia = max(dia, lh + rh); // diameter is just sum of left height and right height of tree

    return 1 + max(lh, rh);
}
int main()
{
    Node *head = createTree();
    cout << "Diameter of BT is : ";
    int dia = 0;
    diameter(head, dia);
    cout << dia;

    return 0;
}