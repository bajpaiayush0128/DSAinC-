#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    string s = "AABBAA";
    cout << isPalindrome(s, 0, s.length() - 1);
    return 0;
}

// 3. factorial
