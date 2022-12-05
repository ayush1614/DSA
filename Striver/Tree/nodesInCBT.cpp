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

// find the left height
int leftHeight(Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->lchild;
    }
    return height;
}

// find the right height
int rightHeight(Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->rChild;
    }
    return height;
}

// counting the nodes in complete Binary tree in Less than O(n) time complexity
int cntCBT(Node *root)
{
    if (root == nullptr)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    // if both heights are equal
    if (lh == rh)
        return pow(2, lh) - 1;

    // otherwise traverse further
    return 1 + cntCBT(root->lchild) + cntCBT(root->rChild);
}

int main()
{
    Node *root = createTree();
    int cnt = cntCBT(root);
    cout << "Number of nodes in CBT: " << cnt;
    return 0;
}