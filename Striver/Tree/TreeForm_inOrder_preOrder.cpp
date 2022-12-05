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

// stores the index of all elments of inorder pattern 
void buildTree(vector<int> inorder, unordered_map<int, int> &ump)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        ump[inorder[i]] = i;
    }
}

// making the tree
Node *makeTree(vector<int> inOrder, int inStart, int inEnd, vector<int> preOrder, int preStart, int preEnd, unordered_map<int, int> ump)
{
    if (preStart > preEnd or inStart > inEnd)
        return nullptr;

    Node *root = new Node(preOrder[preStart]);
    
    //getting the index of root node 
    int inRoot = ump[root->data];
    
    //figuring the elements include on left side and right side   
    int numLeft = inRoot - inStart;

    //connecting the left child
    root->lchild = makeTree(inOrder, inStart, inRoot - 1, preOrder, preStart + 1, preStart + numLeft, ump);
    //connecting the right child
    root->rChild = makeTree(inOrder, inRoot + 1, inEnd, preOrder, preStart + numLeft + 1, preEnd, ump);

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
        if (curr->lchild)
            q.push(curr->lchild);

        if (curr->rChild)
            q.push(curr->rChild);
    }
}
int main()
{
    vector<int> inOrder = {40, 20, 50, 10, 60, 30};
    vector<int> preOrder = {10, 20, 40, 50, 30, 60};

    int n = 6;
    unordered_map<int, int> ump;
    buildTree(inOrder, ump); // just to store the index of each node
    // for(auto i:ump)
    // cout<<i.first<<" " <<i.second<<endl;
    Node *root = makeTree(inOrder, 0, n - 1, preOrder, 0, n - 1, ump);
    cout << "\nLevel order Traversal: ";
    LevelOrderTraversal(root);
    return 0;
}