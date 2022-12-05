// printing the nodes at distance k form a specified node
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

// mark the parents of child nodes
void markParents(Node *root, unordered_map<Node *, Node *> &ump)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    while (!root)
    {
        auto curr = q.front();
        q.pop();

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
}

void nodesAtdistanceKfromSpecifiedNode(Node *root, int k)
{
    if (root == nullptr)
        return;

    unordered_map<Node *, Node *> parents;
    markParents(root, parents);
    unordered_map<Node *, bool> visited; // so that we cannot visit a node twice
    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int level = 0; // checks for the current level
    while (!q.empty())
    {
        int n = q.size();
        if (level == k) // if level==k jst break the loop || otherwise increase the level++ ;
            break;
        level++;

        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();

            // radiate left
            if (curr->lchild and visited[curr->lchild] == false)
            {
                visited[curr->lchild] = true;
                q.push(curr->lchild);
            }

            // radiate right
            if (curr->rChild and visited[curr->rChild] == false)
            {
                visited[curr->rChild] = true;
                q.push(curr->rChild);
            }

            //radiate up
            if (visited[parents[curr]] == false)
            {
                visited[parents[curr]] = true;
                q.push(parents[curr]);
            }
        }
    }
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        cout << curr->data << ' ';
    }
}
int main()
{
    Node *root = createTree();
    int k; // Time complexity :- O(n) +  O(n)  = O(n) || Space complexity:-  O(n) + O(n) + O(n) = O(n)
    cout << "Enter distance K : ";
    cin >> k;
    nodesAtdistanceKfromSpecifiedNode(root, k);
}