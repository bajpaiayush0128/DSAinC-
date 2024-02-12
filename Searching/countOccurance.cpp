#include <iostream>
using namespace std;

int firstOcc(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x > arr[mid])
        return firstOcc(arr, mid + 1, high, x);
    else if (x < arr[mid])
        return firstOcc(arr, low, mid - 1, x);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return firstOcc(arr, low, mid - 1, x);
    }
}

int lastOcc(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x > arr[mid])
        return lastOcc(arr, mid + 1, high, x);
    else if (x < arr[mid])
        return lastOcc(arr, low, mid - 1, x);
    else
    {
        if (mid == 0 || arr[mid + 1] != arr[mid])
            return mid;
        else
            return lastOcc(arr, mid + 1, high, x);
    }
}

int countOcc(int arr[], int n, int x)
{
    int low = 0, high = n;
    int first = firstOcc(arr, low, high, x);
    if (first == -1)
        return 0;
    else
        return lastOcc(arr, low, high, x) - first + 1;
}

int main()
{

    return 0;
}