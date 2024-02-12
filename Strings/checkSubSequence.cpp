#include <iostream>
using namespace std;

bool isSubsequence(string &str1, string &str2, int n, int m)
{
    if (n < m)
        return false;
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (str1[i] == str2[j])
            j++;
    }
    return (j == m);
}

// use const and reference for optimisation
bool isSubSeqRec(string &str1, string &str2, int n, int m)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str1[n - 1] == str2[m - 1])
        return isSubSeqRec(str1, str2, n - 1, m - 1);
    else
        return isSubSeqRec(str1, str2, n - 1, m);
}

int main()
{

    return 0;
}