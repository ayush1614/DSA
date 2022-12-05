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
void storeHash(vector<int> &inorder, unordered_map<int, int> &ump)
{
    for (int i = 0; i < inorder.size(); i++)
        ump[inorder[i]] = i;
    
}

Node *buildTree(vector<int> &inorder, int instart, int inend, vector<int> postorder, int poststart, int postend, unordered_map<int, int> ump)
{
    if ((poststart > postend) or (instart > inend))
        return nullptr;

    Node *root = new Node(postorder[postend]);
    int idxroot = ump[root->data];
    int numleft = idxroot - instart;

    //making the left child 
    root->lchild = buildTree(inorder, instart, idxroot - 1, postorder, poststart, poststart + numleft-1, ump);
    
    // making the right child 
    root->rChild = buildTree(inorder, idxroot +1, inend, postorder, poststart + numleft , postend-1, ump);

    return root ; 
}

Node *makeTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> ump;
    storeHash(inorder, ump);
    
    return buildTree(inorder, 0, inorder.size()-1, postorder,0, postorder.size() - 1, ump);
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

int main(){
    vector<int> inOrder = {40, 20, 50, 10, 60, 30};
    vector<int> postOrder = {10, 20, 40, 50, 30, 60};

    Node *root = makeTree(inOrder , postOrder);
    cout<<root->data ; 
    // printing the tree
    LevelOrderTraversal(root) ; 

    return 0 ;

}