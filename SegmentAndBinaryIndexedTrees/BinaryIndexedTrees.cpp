// also called Fenwick tree
#include <iostream>
using namespace std;

#define n 10

// turn off the last set bit
// i - i&(-i)

int biTree[n + 1];
int arr[n];
int getSum(int i)
{
    i = i + 1;
    int res = 0;
    while (i > 0)
    {
        res = res + biTree[i];
        i = i - i & (-i);
    }
    return res;
}

// add 1 to last set bit
// i + i&(-i)
void updateTree(int i, int x)
{
    i = i + 1;
    int diff = x - arr[i];
    arr[i] = x;
    while (i <= n)
    {
        biTree[i] += diff;
        i = i + i & (-i);
    }
}

int main()
{

    return 0;
}