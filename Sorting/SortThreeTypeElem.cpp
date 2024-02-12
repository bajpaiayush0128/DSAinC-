#include <iostream>
using namespace std;

// Dutch National Flag ALgorithm
void sort(int arr[], int n)
{
    int l = 0, h = n - 1, mid = 0;
    while (mid <= h)
    {
        if (arr[mid] == 0)
        {
            swap(arr[l], arr[mid]);
            l++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[h]);
            h--;
        }
    }
}
int main()
{

    return 0;
}