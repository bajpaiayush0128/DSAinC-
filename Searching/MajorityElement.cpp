// moore's voting algorithm
#include <iostream>
using namespace std;

int findMajority(int arr[], int n)
{
    int res = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (res == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = arr[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (res == arr[i])
            count++;
    }
    if (count <= n / 2)
        res = -1;
    return res;
}

int main()
{

    return 0;
}