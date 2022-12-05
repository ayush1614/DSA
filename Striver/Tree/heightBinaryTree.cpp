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

// using queue
int height(Node *root)
{
    if (root == NULL)
        return -1;

    int height = 0;
    queue<Node *> q;

    // Pushing first level element along with NULL
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *root = q.front();
        q.pop();

        // When NULL encountered, increment the value
        if (root == NULL)
            height++;

        // If not  NULL , keep moving
        if (root != NULL)
        {
            if (root->lchild)
                q.push(root->lchild);

            if (root->rChild)
                q.push(root->rChild);
        }

        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty())
            q.push(NULL);
    }
    return height - 1;
}

// using recursion
int heightTree(Node *root)
{
    if (root == NULL) // empty tree has height 1
        return -1;

    int x = heightTree(root->lchild);
    int y = heightTree(root->rChild);

    return max(x, y) + 1;
}


int main()
{
    Node *root = createTree();

    int h1 = height(root); // using queue
    cout << "Height of Binary tree using queue is : " << h1;

    int h2 = heightTree(root); // using recursion
    cout << "\nHeight of Binary Tree using recursion : " << h2;
    return 0;
}