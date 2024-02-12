#include <iostream>
using namespace std;

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

int lastOcc1(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] > x)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}