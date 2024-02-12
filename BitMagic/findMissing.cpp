#include <iostream>
using namespace std;

int findMissing(int arr[], int n)
{
    int res = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ arr[i];
    }
    for (int i = 1; i <= (n + 1); i++)
    {
        y = y ^ i;
    }
    return x ^ y;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nMissing number: " << findMissing(arr, n);
    return 0;
}