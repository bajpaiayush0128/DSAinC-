#include <iostream>
using namespace std;

// naive partiton is stable
// last element is pivot, if any other given just swap it with last
// not stable
int lomutoPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

// first element is pivot
// here pivot is not at its correct place
// only ensures that elements before j are smaler and after j are larger
// not stable
int hoarePartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSLomuto(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lomutoPartition(arr, l, h);
        quickSLomuto(arr, l, p - 1);
        quickSLomuto(arr, p + 1, h);
    }
}

void quickSHoare(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = hoarePartition(arr, l, h);
        quickSHoare(arr, l, p);
        quickSHoare(arr, p + 1, h);
    }
}

// tail call elimination
void quickSHoare(int arr[], int l, int h)
{
Begin:
    if (l < h)
    {
        int p = hoarePartition(arr, l, h);
        quickSHoare(arr, l, p);
        l = p + 1;
        goto Begin;
    }
}

int main()
{

    return 0;
}