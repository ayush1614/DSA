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

// chk for the left and then right tree , if reaches null , then we can't find the given node then popback
// the last added value and move to right subtree, if same then do the same
// but if we get the node then return true from that node
bool getpath(Node *root, int x, vector<int> &vec)
{
    if (root == nullptr)
        return false;

    vec.push_back(root->data);

    if (root->data == x)
        return true;

    if (getpath(root->lchild, x, vec) or getpath(root->rChild, x, vec))
        return true;

    vec.pop_back();
    return false;
}
vector<int> nodePath(Node *root, int z)
{
    vector<int> arr;
    if (root == nullptr)
        return arr;

    getpath(root, z, arr);

    return arr;
}

int main()
{
    Node *root = createTree();
    cout << "Root to given node : ";
    vector<int> vec = nodePath(root, 7);
    for (auto i : vec)
        cout << i << " ";
    return 0;
}