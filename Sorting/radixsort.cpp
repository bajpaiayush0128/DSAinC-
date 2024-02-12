#include <iostream>
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int count[10]; // k is 10 as digits are 0 to 9
    for (int i = 0; i < 10; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] = count[i - 1] + count[i];
    int output[n];
    for (int i = n - 1; i >= 0; i--) // we can alo traverse from 0 to n-1, but we do this to keep algo stable
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int exp = 1; max / exp > 0; exp = exp * 10)
        countSort(arr, n, exp);
}

// space theta(n+b)
// time complexity theta(d*(n+b))
// b is base
// if we want to decrease time complexity increase b, but it will increase space complexity
// there will be less no of digits on bigger base

int main()
{

    return 0;
}