#include <iostream>
using namespace std;

void patSearching(string &str, string &pat)
{
    int m = pat.length();
    int n = str.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != str[i + j])
                break;
        }
        if (j == m)
            cout << i << " ";
    }
}

void patSearchDist(string &str, string &pat)
{
    int m = pat.length();
    int n = str.length();
    for (int i = 0; i <= n - m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != str[i + j])
                break;
        }
        if (j == m)
            cout << i << " ";
        if (j == 0)
            i++;
        else
            i = i + j;
    }
}

int main()
{

    return 0;
}