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

Node *insertNode(Node *root, Node *tmp)
{
    if (root == nullptr)
        return tmp;

    auto curr = root;
    while (true)
    {
        if (curr->data <= tmp->data)
        {
            if (curr->rChild)
                curr = curr->rChild;

            else
            {
                curr->rChild = tmp;
                break;
            }
        }
        else
        {
            if (curr->lchild)
                curr = curr->lchild;

            else
            {
                curr->lchild = tmp;
                break;
            }
        }
    }
    return root ; 
}

void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->lchild)
            q.push(curr->lchild);

        if (curr->rChild)
            q.push(curr->rChild);
    }
}

int main()
{
    Node *root = createTree();
    Node *curr = new Node(5);
    root = insertNode(root, curr);

    LevelOrderTraversal(root);
    return 0;
}

// many trees are possible , we have to make any one of them . So we append the node at the null point 
// Time: O(log2(n))  tree is height balanced