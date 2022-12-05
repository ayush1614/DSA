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

Node *lcaBST(Node *root, Node *a, Node *b)
{
    if (root == nullptr)
        return nullptr;

    auto curr = root;
    while (curr)
    {
        if (curr->data > a->data and curr->data > b->data)
            curr = curr->lchild;

        else if (curr->data < a->data and curr->data < a->data)
            curr = curr->rChild;

        else
            return curr;
    }
    return root;
}

int main()
{
    Node *root = createTree();
    Node *a = new Node(5);
    Node *b = new Node(9);
    Node *lca = lcaBST(root , a,b);
    cout<<"LCA of BST is "<<lca->data ; 
}