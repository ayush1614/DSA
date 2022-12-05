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

stack<Node *> st;

// push all the lefts in the stack
void pushAll(Node *root)
{
    while (root)
    {
        st.push(root);
        root = root->lchild;
    }
}

// returns the next smalleest number
Node *next()
{
    auto curr = st.top();
    st.pop();

    pushAll(curr->rChild);
    return curr;
}

// checks whether the next smallest exists of not
bool hashNext()
{
    return !st.empty();
}

void bstIterator(Node *root)
{
    pushAll(root);
}

int main()
{
    Node *root = createTree();
    bstIterator(root);
    Node *curr = next();
    cout<<curr->data<<endl;
    curr = next();
    cout<<curr->data<<endl;
    if (hashNext())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}