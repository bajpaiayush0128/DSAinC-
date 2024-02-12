#include <iostream>
using namespace std;

int lcm(int a, int b)
{
    int res = max(a, b);
    while (true)
    {
        if (res % a == 0 && res % b == 0)
            return res;
        res++;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm1(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a = 5, b = 7;
    cout << "LCM is: " << lcm1(a, b);
    return 0;
}