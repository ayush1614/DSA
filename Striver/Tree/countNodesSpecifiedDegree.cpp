#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
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

int countNodesDegreeZero(Node *root)
{
    if (root != NULL)
    {
        int x = countNodesDegreeZero(root->lchild); // count left side nodes
        int y = countNodesDegreeZero(root->rChild); // count right side nodes

        if (root->lchild == NULL && root->rChild == NULL) // if both childs are null then consider it otherise leave it
            return x + y + 1;

        else
            return x + y;
    }
    return 0;
}

int countNodesDegreeOne(Node *root)
{
    if (root != NULL)
    {
        int x = countNodesDegreeOne(root->lchild);
        int y = countNodesDegreeOne(root->rChild);

        if (root->lchild != NULL && root->rChild == NULL)
            return x + y + 1;

        else if (root->rChild != NULL && root->lchild == NULL)
            return x + y + 1;

        else
            return x + y;
    }
    return 0;
}

int countNodesDegreeTwo(Node *root)
{
    if (root != NULL)
    {
        int x = countNodesDegreeTwo(root->lchild);
        int y = countNodesDegreeTwo(root->rChild);

        if (root->lchild != NULL && root->rChild != NULL)
            return x + y + 1;

        else
            return x + y;
    }
    return 0;
}

int main()
{
    Node *root = createTree();
    int n = countNodesDegreeZero(root);
    cout << "Nodes having degree 0 : " << n << endl;

    n = countNodesDegreeOne(root);
    cout << "Nodes having degree 1 : " << n << endl;

    n = countNodesDegreeTwo(root);
    cout << "Nodes having degree 2  : ";
    return 0;
}