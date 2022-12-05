#include <bits/stdc++.h>            // Time Complexity : O(n) || Space Complexity : O(1)
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
Node *createTree()
{
    int dt;
    cout << "Enter the root data(-1 for null) : ";
    cin >> dt;
    if (dt == -1)
        return nullptr;

    Node *root = new Node(dt);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int ldt;
        cout << "Enter left child data(-1 for null) " << curr->data << " :";
        cin >> ldt;

        // left child
        if (ldt != -1)
        {
            Node *lnode = new Node(ldt);
            curr->left = lnode;
            q.push(lnode);
        }

        // rigth child
        int rdt;
        cout << "Enter right child data(-1 for null) " << curr->data << " :";
        cin >> rdt;

        if (rdt != -1)
        {
            Node *rnode = new Node(rdt);
            curr->right = rnode;
            q.push(rnode);
        }
    }
    return root;
}

// Inorder traversal using the morris tarversal
void inorderMtraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Root is null";
        return;
    }
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr)
                prev = prev->right;

            // making the thread
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else  // removing the thread
            {
                prev->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

// Preorder traversal using the morris traversal
void preorderMtraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Root is null";
        return;
    }
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }

        else
        {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr)
                prev = prev->right;


            // making the thread
            if (prev->right == nullptr)
            {
                prev->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            }
            else  // removing the thread
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    Node *root = createTree();

    cout << "Inorder Morris traversal : ";
    inorderMtraversal(root);
    
    cout<<"\npreorder Morris traversal : " ; 
    preorderMtraversal(root) ;
}