#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void insert(TrieNode *root, string &key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

bool search(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
        if (root->child[i])
            return false;
    return true;
}

TrieNode *deleteNode(TrieNode *root, string key, int i = 0)
{
    if (root == NULL)
        return NULL;
    if (i == key.length())
    {
        if (root->isEnd)
            root->isEnd = false;
        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] =
        deleteNode(root->child[index], key, i + 1);
    if (isEmpty(root) && root->isEnd == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

int main()
{
    struct TrieNode *root = new TrieNode();
    string s1 = "good";
    string s2 = "goods";
    string s3 = "zebra";
    insert(root, s1);
    insert(root, s2);
    insert(root, s3);
    cout << "Is present: " << search(root, "good");
    cout << "\nDeleted node: " << deleteNode(root, "good");
    return 0;
}