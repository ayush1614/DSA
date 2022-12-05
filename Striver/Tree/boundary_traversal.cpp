#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int x)
    {
        data = x;
        lchild = rchild = NULL;
    }
};
Node *createTree()
{
    int dt;
    cout << "Enter the root(-1 for NULL) : ";
    cin >> dt;

    if (dt == -1)
        return NULL;

    Node *head = new Node(dt);
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // for left child
        int lt;
        cout << "Enter the left child(-1 for  NULL) " << curr->data << ": ";
        cin >> lt;
        if (lt != -1)
        {
            Node *lnode = new Node(lt);
            curr->lchild = lnode;
            q.push(lnode);
        }

        // for right child
        int rt;
        cout << "Enter right child (-1 for NULL) " << curr->data << ": ";
        cin >> rt;
        if (rt != -1)
        {
            Node *rnode = new Node(rt);
            curr->rchild = rnode;
            q.push(rnode);
        }
    }
    return head;
}
bool isleaf(Node *root)
{
    return (root->lchild == nullptr and root->rchild == NULL) ? true : false;
}

// traversing the left boundary , if left not exists , goto right then left . Repeat for same condition .
void leftboundary(Node *root, vector<int> &vec)
{
    Node *curr = root->lchild;
    while (curr)
    {
        if (!isleaf(curr))
            vec.push_back(curr->data);

        if (curr->lchild)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
}

// we can get the leaf nodes using the inorder traversal
void leafnodes(Node *root, vector<int> &vec)
{
    if (isleaf(root))
    {
        vec.push_back(root->data);
        return;
    }

    if (root->lchild)
        leafnodes(root->lchild, vec);
    if (root->rchild)
        leafnodes(root->rchild, vec);
}

// traversing the right boundary and if right child not exist go to left and then its right . Repeat for same conditions .
void rightBoundary(Node *root, vector<int> &vec)
{
    Node *curr = root->rchild;
    vector<int>tmp ; 
    while (curr)
    {
        if (!isleaf(curr))
            tmp.push_back(curr->data);

        if (curr->rchild)
            curr = curr->rchild;
        else
            curr = curr->lchild;
    }
    // for reverse order storing 
    reverse(tmp.begin(),tmp.end()) ; 
    vec.insert(vec.end() , tmp.begin(),tmp.end()) ; 
}

int main()
{
    Node *root = createTree();
    vector<int> vec;

    if (root == nullptr)
        cout << "Root is null : ";

    if (!isleaf(root))
        vec.push_back(root->data);

    leftboundary(root, vec);
    leafnodes(root, vec);
    rightBoundary(root, vec);

    cout << "Boundary order traversal is : ";
    for (auto &i : vec)
        cout << i << " ";

    return 0;
}