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
vector<int> pre, post, in;

void allTraversal(Node *head)
{
    if (head == NULL)
        return;

    stack<pair<Node *, int>> st;
    st.push({head, 1});

    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr.second == 1) // for preorder
        {
            pre.push_back(curr.first->data);
            curr.second++;
            st.push(curr);

            if (curr.first->lchild != nullptr)
                st.push({curr.first->lchild, 1});
        }
        else if (curr.second == 2) // for preorder
        {
            in.push_back(curr.first->data);
            curr.second++;
            st.push(curr);

            if (curr.first->rchild != NULL)
                st.push({curr.first->rchild, 1});
        }
        else // for postorder
            post.push_back(curr.first->data);
    }
    return;
}

int main()
{
    Node *head = createTree();
    allTraversal(head);
    cout << "Inorder traaversal: ";
    for (auto &i : in)
        cout << i << " ";

    cout << "\nPreorder Traversal : ";
    for (auto &i : pre)
        cout << i << " ";

    cout << "\nPostorder Traversal : ";
    for (auto &i : post)
        cout << i << " ";

    return 0;
}