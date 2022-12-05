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

// intusion behind is that , it is not given that we cannot change the value of nodes
// so if root value>= left+right ==> left = right = root value 
// else root->data = left+right value
void childrenSum(Node *root)
{
    if (!root)
        return;

    int child = 0;
    if (root->lchild)
        child += root->lchild->data;

    if (root->rChild)
        child += root->rChild->data;

    //comparing root data  is less than sum of child data , if yes then updated root data
    if (root->data <= child)
        root->data = child;
    //otherwise update child data
    else
    {
        if (root->lchild)
            root->lchild->data = root->data;

        if (root->rChild)
            root->rChild->data = root->data;
    }
    
    childrenSum(root->lchild);   //moving to left 
    childrenSum(root->rChild);  // moving to right 

    // when we backtrack then we update the node
    int total = 0;
    if (root->lchild)
        total += root->lchild->data;
    if (root->rChild)
        total += root->rChild->data;
        
    // update only if it is not the leaf node 
    if (root->lchild or root->rChild )
        root->data = total;
}
void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree not contain any node";
        return;
    }

    queue<Node *> q;
    q.push(root);
    while (root != NULL || !q.empty())
    {
        root = q.front();
        q.pop();

        cout << root->data << " "; // print root data

        if (root->lchild) //  push left child in queue
            q.push(root->lchild);

        if (root->rChild) // push right child in queue
            q.push(root->rChild);
    }
}

int main()
{
    Node *root = createTree();
    childrenSum(root);
    cout << "Tree after applying children sum property: ";
    LevelOrderTraversal(root);

    return 0;
}