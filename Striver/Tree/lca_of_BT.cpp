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

//TC: O(n)  || SC: O(N)   : in worst case it will be O(n) i.e skew trees
Node* lca(Node *root, Node *p, Node *q)
{
    if (root == nullptr or p == root or q == root)
        return root;

    Node *left = lca(root->lchild, p, q);
    Node *right = lca(root->rChild, p, q);

    if(left==NULL)
    return right ; 

    else if(right==NULL)
    return left ; 

    else
    return root ; 
}

int main()
{
    Node *root = createTree();
    cout << "Lowest common ancestor : ";
    Node *lc =  lca(root, new Node(2), new Node(3));
    cout<<lc->data ; 
    return 0;
}