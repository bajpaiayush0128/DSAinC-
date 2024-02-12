#include <iostream>
using namespace std;

int logPropPreSuff(string &str, int n)
{
    for (int len = n - 1; len > 0; len--)
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[n - len + i])
                flag = false;
        }
        if (flag == true)
            return len;
    }
    return 0;
}
void fillLPS(string &str, int lps[])
{
    for (int i = 0; i < str.length(); i++)
        lps[i] = logPropPreSuff(str, i + 1);
}

// efficeint approach
void fill_lps(string &str, int lps[])
{
    int n = str.length(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void KMP(string &str, string &pat)
{
    int n = str.length();
    int m = pat.length();
    int lps[m];
    fill_lps(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << " "; // also i-m can be printed
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != str[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string str = "absdfghab";
    string pat = "ab";
    KMP(str, pat);
    return 0;
}