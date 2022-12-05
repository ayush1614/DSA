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

void verticalTraversal(Node *root)
{
    if (root == nullptr)
        return;

    Node *curr = root;
    int level = 0, vert = 0;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({curr, {0, 0}});
    map<int, map<int, multiset<int>>> mp;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.second.first, y = curr.second.second;

        mp[x][y].insert(curr.first->data);

        if (curr.first->lchild)
            q.push({curr.first->lchild, {x - 1, y + 1}});

        if (curr.first->rchild)
            q.push({curr.first->rchild, {x + 1, y + 1}});
    }
    vector<vector<int>> vec;
    for (auto i : mp)
    {
        vector<int> arr;
        for (auto j : i.second)
            arr.insert(arr.end(), j.second.begin(), j.second.end());

        vec.push_back(arr);
    }
    for (auto i : vec)
    {
        for (auto j : i)
            cout << j << " ";

        cout << endl;
    }
}

int main()
{
    Node *root = createTree();
    verticalTraversal(root);
}