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

// diffrence b/w left and right height subtree should not more than 1 : Balanced Binary Tree 
int balancedBST(Node *head)
{
    if (head == NULL)
        return 0;

    int lheight = balancedBST(head->lchild);
    int rheight = balancedBST(head->rchild);

    if (lheight == -1 || rheight == -1)
        return -1;

    else if (abs(lheight - rheight)> 1)
        return -1;

    return max(lheight, rheight) + 1;
}
int main()
{
    Node *head = createTree();
    cout << "Is it balanced BST : ";
    int res = balancedBST(head);
    if (res != -1)
        cout << "YES" << endl;

    else
        cout << "NO" << endl;

    return 0;
}