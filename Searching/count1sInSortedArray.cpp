// binary array
#include <iostream>
using namespace std;

int count1s(int arr[], int low, int high, int x)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x > arr[mid])
        return count1s(arr, mid + 1, high, x);
    else if (x < arr[mid])
        return count1s(arr, low, mid - 1, x);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid]) // arr[mid-1]==0
            return n - mid;
        else
            return count1s(arr, low, mid - 1, x);
    }
}

int main()
{

    return 0;
}