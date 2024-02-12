#include <iostream>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int result = max(max(maxCuts(n - a, a, b, c), maxCuts(n - b, a, b, c)), maxCuts(n - c, a, b, c));
    if (result == -1)
        return -1;
    return (result + 1);
}

int main()
{
    int n = 9;
    int a = 2;
    int b = 2;
    int c = 2;
    cout << maxCuts(n, a, b, c);
    return 0;
}