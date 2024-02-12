#include <iostream>
#include <algorithm>
using namespace std;
const int CHAR = 256;

bool areAnagram(string &pat, string &str, int i)
{
    int count[CHAR] = {0};
    for (int j = 0; j < str.length(); j++)
    {
        count[pat[i]]++;
        count[str[i + j]]--;
    }
    for (int j = 0; j < CHAR; j++)
    {
        if (count[j] != 0)
            return false;
    }
    return true;
}

bool isPresent(string &str, string &pat)
{
    int n = str.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++)
    {
        if (areAnagram(pat, str, i))
            return true;
    }
    return false;
}

bool areSame(int arr1[], int arr2[])
{
    int N = sizeof(arr1) / sizeof(arr1[0]);
    int M = sizeof(arr2) / sizeof(arr2[0]);
    if (N != M)
        return false;
    sort(arr1, arr1 + N);
    sort(arr2, arr2 + M);
    for (int i = 0; i < N; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

bool isPresent1(string &str, string &pat)
{
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        CT[str[i]]++;
        CP[pat[i]]++;
    }
    for (int i = pat.length(); i < str.length(); i++)
    {
        if (areSame(CT, CP))
            return true;
        CT[str[i]]++;
        CT[str[i - pat.length()]]--;
    }
    return false;
}

int main()
{
    string str = "abcderhgftl";
    string pat = "rde";
    cout << isPresent1(str, pat);
    return 0;
}