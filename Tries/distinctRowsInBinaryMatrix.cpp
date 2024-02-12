#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
bool mat[3][4];

bool insert(TrieNode *root, int row)
{
    TrieNode *curr = root;
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        int index = mat[row][i];
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
        return flag;
    }
}

int countDistinct()
{
    TrieNode *root = new TrieNode();
    int res = 0;
    for (int i = 0; i < 3; i++)
        if (insert(root, i) == true)
            res++;
    return res;
}

int main()
{

    return 0;
}