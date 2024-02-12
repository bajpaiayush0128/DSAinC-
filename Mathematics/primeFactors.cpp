#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void primeFactors(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            int x = i;
            while (n % x == 0)
            {
                cout << i << " ";
                x = x * i;
            }
        }
    }
}

void primeFactors2(int n)
{
    if (n <= 1)
        return;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1)
        cout << n << " ";
}

void primeFactors3(int n)
{
    if (n <= 1)
        return;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n = n / 3;
    }
    for (int i = 5; i < sqrt(n); i = i + 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }
    if (n > 3)
        cout << n << " ";
}

int main()
{
    int x = 84;
    primeFactors3(x);
    return 0;
}