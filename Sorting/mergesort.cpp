#include <iostream>
#include <algorithm>
using namespace std;

void mergeSort(int a[], int b[], int m, int n)
{
    int c[m + n];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    for (int i = 0; i < n; i++)
        c[i] = b[i];
    sort(c, c + m + n);
    for (int i = 0; i < (m + n); i++)
        cout << c[i] << " ";
}

void mergeSort1(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << b[j] << " ";
        j++;
    }
}

void mergeSortRec(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortRec(arr, l, m);
        mergeSortRec(arr, m + 1, r);
        // merge(arr, l, m, r);  it is same as first function, using left and right subarrays
    }
}

int main()
{

    return 0;
}