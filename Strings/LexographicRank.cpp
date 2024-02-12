#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

const int CHAR = 256;
int lexRank(string &str)
{
    int res = 1;
    int n = str.length();
    int mul = factorial(n);
    int count[CHAR] = {0};
    for (int i = 0; i < n; i++)
        count[str[i]]++;
    for (int i = 1; i < CHAR; i++)
        count[i] += count[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res = res + count[str[i] - 1] * mul;
        for (int j = str[i]; j < CHAR; j++)
        {
            count[j]--;
        }
        return res;
    }
}

int main()
{

    return 0;
}