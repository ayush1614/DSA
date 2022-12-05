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

// Preorder tree traversal
void PreOrder1(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    while (root != NULL || !st.empty())
    {
        if (root != NULL) // if root is null , print root data and store the root address for right node traversal
        {
            cout << root->data << " ";
            st.push(root);
            root = root->lchild;
        }
        else // if root is null , pop out the data  , and move root to right node
        {
            root = st.top();
            st.pop();
            root = root->rChild;
        }
    }
}

// Better understandable from above method:  TC: O(n)  || SC: O(n)
void PreOrder2(Node *root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        cout << root->data<<" ";

        if (root->rChild)
            st.push(root->rChild);

        if (root->lchild)
            st.push(root->lchild);
    }
}
int main()
{
    Node *root = createTree();
    cout << "PreOrder traversal: ";
    PreOrder1(root);
    cout << endl;
    PreOrder2(root);
    return 0;
}