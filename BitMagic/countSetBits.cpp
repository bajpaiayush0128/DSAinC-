#include <iostream>
using namespace std;

int countSet(int n)
{
    int res = 0;
    while (n > 0)
    {
        if ((n & 1) == 1) // res = res+(n&1)
            res++;
        n = n >> 1;
    }
    return res;
}

// Brian Kerningam's Algorithm
int countBits(int n)
{
    int res = 0;
    while (n > 0)
    {
        n = (n & (n - 1)); // when you make n to (n-1) all the bits after last set bit become 1 and last set bit becomes 0
        res++;
    }
    return res;
}

// lookup table method
int table[256];
void initialize()
{
    table[0] = 0;
    for (int i = 1; i < 256; i++)
        table[i] = (i & 1) + table[i / 2];
}

int countBit(int n)
{
    table[0] = 0;
    for (int i = 1; i < 256; i++)
        table[i] = (i & 1) + table[i / 2];
    // int res = table[n & 0xff] + table[(n >> 8) & 0xff] + table[(n >> 16) & 0xff] + table[(n >> 24) & 0xff];
    int res = table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    return res;
}

int main()
{
    int n = 5;
    cout << countSet(n) << endl;
    cout << countBits(n) << endl;
    cout << countBit(n) << endl;
    return 0;
}