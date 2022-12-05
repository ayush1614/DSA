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

// here we use the reverse of preorder tarversal ,  (ROOT , RIGHT , LEFT)
void recurse(Node *root , int level , vector<int>&vc)
{
    if(root==nullptr)
    return ;

    // here use data structure , if sz is equal to this then push in data structure 
    if(vc.size()==level)
    vc.push_back(root->data) ; 

    if(root->rChild)
    recurse(root->rChild , level + 1 , vc) ; 

    if(root->lchild)
    recurse(root->lchild , level + 1 , vc) ; 
}

// right view of binary tree
void rightView(Node *root)
{
    vector<int> rv;
    recurse(root, 0,rv);
    for (auto &i : rv)
        cout << i << " ";
}
int main()
{
    Node *root = createTree();
    cout << "Right view of binary tree : ";
    rightView(root);

    return 0 ; 
}

// here we not use the level order traversal because it uses extra space to store all the node 
//of a level  