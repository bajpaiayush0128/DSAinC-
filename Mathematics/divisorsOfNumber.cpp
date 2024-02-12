#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
}

void printDivisors2(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            {
                if (i != n / i)
                    cout << n / i << " ";
            }
        }
    }
}

void printDivisors3(int n)
{
    int i;
    for (i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << n / i << " ";
        }
    }
}

int main()
{
    int x = 124;
    printDivisors3(x);
    return 0;
}