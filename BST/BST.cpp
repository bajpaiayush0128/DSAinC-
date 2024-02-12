#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

bool search(Node *root, int v)
{
    if(root==NULL) return false;
    else if(root->key==v) return true;
    else if(root->key>v) return search(root->left, v);
    else return search(root->right, v);
}

bool iterativeSearch(Node *root, int v)
{
    while(root!=NULL)
    {
        if(root->key==v) return true;
        else if(root->key>v) root = root->left;
        else root = root->right;
    }
    return false;
}

Node *insert(Node *root, int x)
{
    if(root==NULL) return new Node(x);
    else if(root->key>x) root->left = insert(root->left, x);
    else if(root->key<x) root->right = insert(root->right, x);
    return root;
}

Node *iterativeInsert(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while(curr!=NULL)
    {
        parent = curr;
        if(curr->key>x) curr = curr->left;
        else if(curr->key<x) curr = curr->right;
        else return root;
    }
    if(parent==NULL) return temp;
    if(parent->key>x) parent->left = temp;
    else parent->right = temp;
    return root;
}

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while(curr!=NULL&&curr->left!=NULL) curr = curr->left;
    return curr;
}

Node *delNode(Node *root, int x)
{
    if(root==NULL) return root;
    if(root->key>x) root->left = delNode(root->left, x);
    else if(root->key<x) root->right = delNode(root->right, x);
    else
    {
        if(root->left==NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }
    }
    return root;
}

Node *floor(Node *root, int x)
{
    Node *result = NULL;
    while(root!=NULL)
    {
        if(root->key==x) return root;
        else if(root->key>x) root = root->left;
        else
        {
            result = root;
            root = root->right;
        }
    }
    return result;
}

Node *ceil(Node *root, int x)
{
    Node *result = NULL;
    while(root!=NULL)
    {
        if(root->key==x) return root;
        else if(root->key<x) root = root->right;
        else
        {
            result = root;
            root = root->left;
        }
    }
    return result;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(10);
    cout << "result of search is: " << search(root, 3) << endl;
    cout << "result of search(iterative) is: " << iterativeSearch(root, 8) << endl;
    root = insert(root, 5);
    cout << "result of search(iterative) is: " << iterativeSearch(root, 5) << endl;
    root = iterativeInsert(root, 15);
    cout << "result of search(iterative) is: " << iterativeSearch(root, 15) << endl;
    Node *temp = floor(root, 12);
    cout << "floor is: " << temp->key << endl;
    Node *temp1 = ceil(root, 4);
    cout << "ceil is: " << temp1->key << endl;
return 0;
}