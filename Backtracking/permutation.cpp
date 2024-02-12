#include <iostream>
using namespace std;

bool isSafe(string str, int l, int i, int r)
{
    if (l != 0 && str[i - 1] == 'A' && str[i] == 'B')
        return false;
    if (r = l + 1 && str[i] == 'A' && str[i] == 'B')
        return false;
    return true;
}

void permutation(string &s, int i = 0)
{
    if (i == s.length() - 1)
    {
        cout << s << " ";
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        if (isSafe(s, i, j, s.length()))
        {
            swap(s[i], s[j]);
            permutation(s, i + 1);
            swap(s[j], s[i]);
        }
    }
}

int main()
{
    string s = "abcd";
    permutation(s);
    return 0;
}