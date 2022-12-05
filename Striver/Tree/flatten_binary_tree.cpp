#include <bits/stdc++.h>
using namespace std;
class Node // structure of tree
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
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
            tmp->left = lNode;
            q.push(lNode);
        }

        // right child entry
        int rdt;
        cout << "Enter data for right child(-1 for NULL) of " << tmp->data << " : ";
        cin >> rdt;

        if (rdt != -1)
        {
            Node *rNode = new Node(rdt);
            tmp->right = rNode;
            q.push(rNode);
        }
    }
    return rt;
}

/// Recursive traversal
Node *prev1 = nullptr;
void flattenBT(Node *root)
{
    if (root == nullptr)
        return;

    flattenBT(root->right);
    flattenBT(root->left);

    root->right = prev1;        // connecting to previous node 
    root->left = nullptr;       // updating left to null

    prev1 = root;
}

// using stack
void flattenBTStack(Node *root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);

        // appending to the right
        if (!st.empty())
            curr->right = st.top();

        // setting left child as null
        curr->left = nullptr;
    }
}

// using inorder traveersal
void flattenBTInorder(Node *root)
{
    Node *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            Node *pre = cur->left;
            while (pre->right)
                pre = pre->right;
            
            pre->right = cur->right;
            cur->right = cur->left;
            
            cur->left = NULL;
        }
        cur = cur->right;
    }
}
int main()
{
    Node *root = createTree();

    cout << "Flattening of binary tree is : ";
    // flattenBT(root);  //Method 1

    // flattenBTStack(root) ;  // method 2

    flattenBTInorder(root); // method 3

    // printing of linked list
    while (root != nullptr)
    {
        cout << root->data << " ";
        root = root->right;
    }
}