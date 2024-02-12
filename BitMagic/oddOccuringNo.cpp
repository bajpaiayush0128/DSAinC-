#include <iostream>
using namespace std;

void oddOccuring(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count % 2 != 0)
            cout << arr[i];
    }
}

int findOdd(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {4, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    oddOccuring(arr, n);
    cout << "\nOdd occuring: " << findOdd(arr, n);
    return 0;
}