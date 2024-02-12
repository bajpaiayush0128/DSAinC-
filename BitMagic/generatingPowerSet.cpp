#include <iostream>
using namespace std;

int power(int x, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * x;
    }
    return res;
}

void powerSet(string s)
{
    int n = s.length();
    unsigned int powSize = power(2, n);
    for (int i = 0; i < powSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                cout << (s[j]);
        }
        cout << endl;
    }
}

int main()
{
    string s = "abc";
    powerSet(s);
    return 0;
}