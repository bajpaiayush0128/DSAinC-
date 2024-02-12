#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}

const int CHAR = 256;
bool isAnagramStr(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    int count[CHAR] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{

    return 0;
}