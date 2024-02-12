#include <iostream>
#include <cmath>
using namespace std;

// using log function
// log(base a)b = c => b = a^c

int countDigitsUsingLog(int n)
{
    return floor(log10(n) + 1);
}

int main()
{
    int n = 3452;
    cout << "Number of digits : " << countDigitsUsingLog(n);
    return 0;
}
