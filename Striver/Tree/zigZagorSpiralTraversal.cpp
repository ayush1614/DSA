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

// zig zag tarversal means : travelling a level form left to right , next level form right to left , then l->r and so on with levels
vector<vector<int>> spiralTraversal(Node *root)
{
    vector<vector<int>> vec;
    if (root == NULL)
        return vec;

    queue<Node *> q;
    q.push(root) ; 
    Node *curr = NULL;
    vector<int> tmp;
    bool flag = 1;
    while (!q.empty())
    {
        auto n = q.size();
        vector<int> tmp(n);
        for (int i = 0; i < n; i++)
        {
            curr = q.front();
            q.pop();

            int idx = flag ? i : (n - i - 1);
            tmp[idx] = curr->data;

            if (curr->lchild != NULL)
                q.push(curr->lchild);

            if (curr->rchild != NULL)
                q.push(curr->rchild);
        }

        flag = !flag;
        vec.push_back(tmp);
    }
    return vec;
}

int main()
{
    Node *root = createTree();
    cout << "Zig-Zag or Spiral traversal of tree is : "<<endl;
    vector<vector<int>> vec = spiralTraversal(root);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";

        cout << endl;
    }
    return 0;
}