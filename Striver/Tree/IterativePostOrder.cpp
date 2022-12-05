#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Node // structure of tree
{          // pending

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

// Postorder tree traversal : USING TWO STACKS : TC: O(n)   || SC: O(2n)
void PostOrder(Node *p)
{
    stack<Node *> st1, st2;
    st1.push(p);
    while (!st1.empty())
    {
        Node *tmp = st1.top();
        st1.pop();

        st2.push(tmp);

        if (tmp->lchild != nullptr)
            st1.push(tmp->lchild);

        if (tmp->rChild != nullptr)
            st1.push(tmp->rChild);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

//  POST ORDER USING ONLY ONE STACK : TC: O(2N)   | SC:  O(N)
void PostOrder1(Node *root)
{
    stack<Node *> st;
    vector<int> post;
    Node *tmp = nullptr;
    while (!st.empty() or root != nullptr)
    {
        if (root != nullptr)
        {
            st.push(root);
            root = root->lchild;
        }
        else
        {
            tmp = st.top()->rChild;
            if (tmp == nullptr)
            {
                tmp = st.top();
                st.pop();
                post.push_back(tmp->data);

                while (!st.empty() and tmp == st.top()->rChild) // traverse until tos is not equal to tmp 
                {
                    tmp = st.top();
                    st.pop();
                    post.push_back(tmp->data);
                }
            }
            else
                root = tmp;
        }
        for (auto &it : post)
            cout << it << " ";

        cout << endl;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Node *root = createTree();
    cout << "PostOrder traversal: ";
    PostOrder(root); // using two stacks

    PostOrder1(root); // using only one stack
    return 0;
}