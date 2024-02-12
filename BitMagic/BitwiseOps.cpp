#include <iostream>
using namespace std;

int main()
{
    int x = 3, y = 6;
    // 2^32 -1 = 4294967296 - 1 = 4294967295(power become 31 in case of signed int)
    unsigned int z = 5;
    cout << (x & y) << endl; // bitwise and
    cout << (x | y) << endl; // bitwise or
    cout << (x ^ y) << endl; // bitwise xor
    // left-shift
    cout << (x << 1) << endl; // x<<y = x*2^y, where y bits are zero
    cout << (x << 2) << endl;
    // Right-shift
    cout << (y >> 1) << endl; // x>>y = floor(x/2^y)
    cout << (y >> 2) << endl;
    // Not-operator(all bits are inverted)
    cout << (~z) << endl;
    // 2's complement of x in n-bits repersentation is 2^n -x(this is for -ve numbers)
    cout << (~x) << endl;
    return 0;
}