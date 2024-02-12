#include <iostream>
#include <cmath>
#include <vector>
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

void printPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
}

void sieve(int n)
{
    vector<bool> isPrimeNo(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isPrimeNo[i])
        {
            for (int j = 2 * i; j <= n; j = j + i)
            {
                isPrimeNo[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrimeNo[i])
            cout << i << " ";
    }
}
void sieve2(int n)
{
    vector<bool> isPrimeNo(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isPrimeNo[i])
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                isPrimeNo[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrimeNo[i])
            cout << i << " ";
    }
}

int main()
{
    int x = 23;
    printPrime(x);
    cout << endl;
    sieve(x);
    cout << endl;
    sieve2(x);
    return 0;
}