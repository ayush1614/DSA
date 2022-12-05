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

void topView(Node *root)
{
    if (root == NULL)
    {
        cout << "Root is null ";
        return;
    }

    map<int, int> mp;
    int vert = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop() ; 
        if (mp[curr.second] == 0)
            mp[curr.second] = curr.first->data;

        if (curr.first->lchild)
            q.push({curr.first->lchild, curr.second-1});

        if (curr.first->rChild)
            q.push({curr.first->rChild , curr.second + 1});
    }
    for(auto i:mp)
    cout<<i.second<<" " ; 
    return  ;  
}

int main()
{
    Node *root = createTree();
    cout << "Top view of Binary tree : ";
    topView(root);

    return 0;
}