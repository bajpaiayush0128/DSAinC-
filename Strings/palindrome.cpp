#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string &str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (rev == str);
}

bool isPal(string &str)
{
    int begin = 0;
    int end = str.length() - 1;
    while (begin < end)
    {
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main()
{

    return 0;
}