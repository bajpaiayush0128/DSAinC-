#include <iostream>
using namespace std;

// arr[] = {1, 2, 4, 3} 4, 3 is inversion
int countInversion(int arr[], int temp[], int l, int m, int r);
int merge(int arr[], int temp[], int left, int right);
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return merge(arr, temp, 0, array_size - 1);
}

int merge(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = left + (right - left) / 2;

        inv_count += merge(arr, temp, left, mid);
        inv_count += merge(arr, temp, mid + 1, right);

        inv_count += countInversion(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int countInversion(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
    while (i < mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Inversion(s) in array is/are: " << mergeSort(arr, n);
    return 0;
}
