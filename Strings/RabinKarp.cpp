#include <iostream>
using namespace std;

void rabinKarp(string &str, string &pat)
{
    int m = pat.length();
    int n = str.length();
    int h = 1, d = 5, q = 29;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + str[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pat[j] != str[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                cout << i << " ";
        }
        if (i < n - m)
        {
            t = ((d * t - str[i] * h) + str[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{

    return 0;
}