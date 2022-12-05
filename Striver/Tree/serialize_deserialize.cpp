// Serialize and Deserialize the binary tree
#include <bits/stdc++.h>
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

// Serialize :- converting the tree in the string
string serialize(Node *root)
{
    if (root == nullptr)
        return "";

    string str = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == nullptr)
            str += "#,";

        else
            str += to_string(curr->data) + ',';

        if (curr != nullptr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return str;
}

// Desrialize:- converting the string back into the same tree
Node *deserialize(string data)
{
    if (data.length() == 0)
        return nullptr;

    string str;
    stringstream s(data);
    getline(s, str, ',');

    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            curr->left = nullptr;

        else
        {
            Node *lnode = new Node(stoi(str));
            curr->left = lnode;
            q.push(lnode);
        }

        getline(s, str, ',');
        if (str == "#")
            curr->right = nullptr;

        else
        {
            Node *rnode = new Node(stoi(str));
            curr->right = rnode;
            q.push(rnode);
        }
    }
    return root;
}

// this function is just for printing the tree
void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Root is  null";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}
int main()
{
    Node *root = createTree();

    string str = serialize(root);
    cout << "After serializing : " << str << endl;

    Node *root1 = deserialize(str);
    cout << "After deserializing level order tarversal of tree is : ";
    LevelOrderTraversal(root1);

    return 0;
}