#include <iostream>
#include <stack>
#include <queue>
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// there are actually two conventions- one is counting with nodes and other is counting edges
// this one is with nodes
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void printKth(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->key << " ";
    else
    {
        printKth(root->left, k - 1);
        printKth(root->right, k - 1);
    }
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    int count = 0, max = INT_MIN;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->key > max)
            max = curr->key;
        cout << curr->key << " ";
        count++;
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << "\ncount is: " << count << endl;
    cout << "max is: " << max << endl;
}

int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

void iterativeInorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

void iterativePreorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        cout << curr->key << " ";
        st.pop();
        if (curr->right != NULL)
            st.push(curr->right);
        if (curr->left != NULL)
            st.push(curr->left);
    }
}

void iterativepreorderOptimised(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

void iterativePostorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    Node *prev = NULL;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            if (curr->right == NULL || curr->right == prev)
            {
                cout << curr->key << " ";
                st.pop();
                prev = curr;
                curr = NULL;
            }
            else
                curr = curr->right;
        }
    }
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(7);
    inorder(root);
    cout << '\n'
         << height(root) << " ";
    cout << "fdf\n";
    printKth(root, 1);
    cout << "fdf\n";
    levelOrder(root);
    cout << "Size of tree is: " << getSize(root) << endl;
    cout << "Max element is: " << getMax(root) << endl;
    cout << "fdf inorder\n";
    iterativeInorder(root);
    cout << "fdf preorder\n";
    iterativePreorder(root);
    cout << "fdf\n";
    iterativepreorderOptimised(root);
    cout << "fdf\n";
    iterativePostorder(root);
    return 0;
}