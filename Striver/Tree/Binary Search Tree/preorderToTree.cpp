// construct a bst using only preoprder traversal ;
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

Node *createTree(vector<int> &vec, int &i, int bound)
{
    if (i == vec.size() or vec[i] > bound)
        return nullptr;

    Node *root = new Node(vec[i++]);
    root->lchild = createTree(vec, i, root->data);
    root->rChild = createTree(vec, i, bound);

    return root ; 
}

void levelOrder(Node *root)
{
    if (root)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->lchild)
                q.push(curr->lchild);

            else if (curr->rChild)
                q.push(curr->rChild);
        }
    }
}
int main()
{
    vector<int> vec = {8, 5, 1, 7, 10, 12};
    int st =0;
    Node *root = createTree(vec, st, INT_MAX);
    levelOrder(root);
}