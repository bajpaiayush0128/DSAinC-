#include <iostream>
using namespace std;

void permutation(string &s, int i = 0)
{
    if (i == s.length() - 1)
    {
        cout << s << " ";
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        permutation(s, i + 1);
        swap(s[j], s[i]);
    }
}

int main()
{
    string s = "abcd";
    permutation(s);
    return 0;
}