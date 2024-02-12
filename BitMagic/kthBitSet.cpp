#include <iostream>
using namespace std;

// using left-shift
void kthBit(int n, int k)
{
    if (n & (1 << (k - 1)) != 0)
        cout << "yes";
    else
        cout << "no";
}

// using right-shift
void kthBit2(int n, int k)
{
    if (((n >> (k - 1)) & 1) == 1)
        cout << "yes";
    else
        cout << "no";
}

int main()
{
    int n = 8, k = 2;
    kthBit(n, k);
    kthBit2(n, k);
    return 0;
}