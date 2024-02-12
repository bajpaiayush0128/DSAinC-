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

int power1(int x, int n)
{
    if (n == 0)
        return 1;
    int temp = power1(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}

int powerIter(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1) // n % 2 != 0
            res = res * x;
        x = x * x;
        n = n >> 1; // n=n/2
    }
    return res;
}

int main()
{
    int x = 5, y = 3;
    cout << "Power is: " << power(x, y);
    cout << "\nPower is: " << power1(x, y);
    cout << "\nPower is: " << powerIter(x, y);
    return 0;
}