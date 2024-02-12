// for unsorted array hashing technique is better
#include <iostream>
using namespace std;

bool isPair(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == x)
            return true;
        else if (arr[left] + arr[right] > x)
            right--;
        else
            left++;
    }
    return false;
}

// for triplet sum
// bool isTriplet(int arr[], int n, int x)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (isPair(arr, i + 1, n - 1,x - arr[i]))
//             return true;
//     }
//     return false;
// }

int main()
{

    return 0;
}