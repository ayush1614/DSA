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

/*----------- Recursive Traversals------------*/

// Inorder tree traversal
void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->lchild);
    cout << root->data << " ";
    InOrder(root->rChild);
}

// Preorder tree traversal
void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->lchild);
    PreOrder(root->rChild);
}

// Postorder tree traversal
void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->lchild);
    PostOrder(root->rChild);
    cout << root->data << " ";
}
/*----------------------------------------*/

int main()
{
    Node *root = createTree();
    cout << "Inorder traversal: ";
    InOrder(root);
    cout << "\nPreOrder traversal: ";
    PreOrder(root);
    cout << "\nPostOrder traversal: ";
    PostOrder(root);
    return 0;
}