#include <iostream>
using namespace std;

bool powOf2(int n)
{
    if (n == 0)
        return false;
    while (n != 1)
    {
        if (n % 2 != 0)
            return false;
        n = n / 2;
    }
    return true;
}

bool isPowOf2(int n)
{
    if (n <= 0)
        return false;
    return ((n & (n - 1)) == 0);
}

int main()
{
    int n = 8;
    cout << "Is Power of two: " << powOf2(n);
    return 0;
}