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

// without using recursion
void reverseLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    vector<int> vec; // instead of using the vector and reversing  we can use the stack simply
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        vec.push_back(root->data); // pushing data into the vector

        if (root->rChild != NULL) // pushing right child 1st in the queue
            q.push(root->rChild);

        if (root->lchild != NULL) // pushing left child
            q.push(root->lchild);
    }

    reverse(vec.begin(), vec.end());
    for (auto &x : vec)
        cout << x << " ";
}

int main()
{
    Node *root = createTree();

    cout << "Reverse Level order tarversal :  ";
    reverseLevelOrderTraversal(root);

    return 0;
}

