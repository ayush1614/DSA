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

//minimum time to burn the tree
Node *markParents(Node *root, unordered_map<Node *, Node *> &ump, int k)
{
    if (root == nullptr)
        return nullptr;

    queue<Node *> q;
    q.push(root);
    Node *addr;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if (curr->data == k)
            addr = curr;

        if (curr->lchild)
        {
            ump[curr->lchild] = curr;
            q.push(curr->lchild);
        }

        if (curr->rChild)
        {
            ump[curr->rChild] = curr;
            q.push(curr->rChild);
        }
    }
    return addr;
}
int burnTreeTime(Node *root, int k)
{
    if (root == NULL)
        return 0;

    unordered_map<Node *, Node *> parents;
    Node *target = markParents(root, parents, k);
    unordered_map<Node *, bool> visited;

    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int time = 0;
    while (!q.empty())
    {
        int n = q.size();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();

            // radiate left
            if (curr->lchild and visited[curr->lchild] == false)
            {
                flag = 1;
                visited[curr->lchild] = true;
                q.push(curr->lchild);
            }

            // radiate right
            if (curr->rChild and visited[curr->rChild] == false)
            {
                flag = 1;
                visited[curr->rChild] = true;
                q.push(curr->rChild);
            }

            // radiate up
            if (parents[curr] and visited[parents[curr]] == false)
            {
                flag = 1;
                visited[parents[curr]] = true;
                q.push(parents[curr]);
            }
        }
        if (flag)
            time++;
    }
    return time;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Node *root = createTree();
    int k;
    cin >> k;
    cout << "Time taken to burn the tree: ";
    int time = burnTreeTime(root, k);
    cout << time << endl;

    return 0;
}