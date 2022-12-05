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

int maxPathSum(Node *root , int &mx)
{
    if(root==nullptr)
    return 0 ; 

    int lsm = max(0 , maxPathSum(root->lchild, mx)) ; // max path sum of left subtree
    int rsm = max(0 , maxPathSum(root->rchild ,mx)) ; // max path sum of right subtree

    mx = max(mx , lsm+rsm+root->data);

    return max(lsm,rsm) + root->data;
}
int main()
{
    Node *root = createTree() ; 
    int mx = INT_MIN ; 
    int sm = maxPathSum(root,mx); // gives the path chosen with root node 
    cout<<"Maximum path sum : "<<mx ; 

    return 0 ; 
}