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

//chk left and right tree using (ROOT,LEFT,RIGHT) with (ROOT,RIGHT,LEFT) 
bool isSymmetrictree(Node *root1, Node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
        return root1 == root2;

    if (root1->data != root2->data)
        return false;

    return isSymmetrictree(root1->lchild, root2->rChild) and isSymmetrictree(root1->rChild, root2->lchild);
}

bool isSymmmetric(Node *root)
{
    return root == nullptr || isSymmetrictree(root->lchild, root->rChild);
}
int main()
{
    Node *root = createTree();
    cout << "tree is symmetric or not : ";

    if (isSymmmetric(root))
        cout << "Yeah";

    else
        cout << "Nope";
    return 0;
}