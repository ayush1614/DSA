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

//Check if two trees are identical or not
bool isIdentical(Node *root1, Node *root2)
{
    if ((root1 == nullptr) || (root2 == nullptr))
        return root1 == root2;

    else
        return (root1->data == root2->data) and isIdentical(root1->lchild, root2->lchild) and isIdentical(root1->rchild, root2->rchild);
}

int main()
{
    Node *root1 = createTree();
    Node *root2 = createTree();

    cout << "Check whether two trees are identical or not..." ;
    if (isIdentical(root1, root2))
        cout << "Yes";

    else
        cout << "No";

    return 0;
}