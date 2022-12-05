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

int SumOfNodes(Node *root)
{
    if (root != NULL)
    {
        int x = SumOfNodes(root->lchild);
        int y = SumOfNodes(root->rChild);

        return x + y + (int)root->data;
    }
    return 0;
}
int main()
{
    Node *root = createTree();
    int n = SumOfNodes(root);
    cout << "node count is : " << n;
    return 0;
}