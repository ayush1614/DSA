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

// width :- number of nodes in a level b/w any 2 nodes
int mxWidth(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int ch = root->data;
    int ans = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int mn = q.front().second; // to make id starting from zero
        int first = 0, last = 0;
        for (int i = 0; i < sz; i++)
        {
            int curr_id = q.front().second - mn;
            auto *curr = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id;

            if (i == sz - 1)
                last = curr_id;

            if (curr->lchild != nullptr)
                q.push({curr->lchild, curr_id * 2 + 1});

            if (curr->rChild != nullptr)
                q.push({curr->rChild, curr_id * 2 + 2});
        }
        ans = max(ans, (last - first) + 1);
    }
    return ans;
}
int main()
{
    Node *root = createTree();
    int width = mxWidth(root);
    cout << "Maximum width of tree : " << width;

    return 0;
}