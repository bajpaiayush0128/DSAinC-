#include<iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int low =0, high=n-1;
    while(low<high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
}

int main()
{
    int arr[] = {1, 0, 0, 4, 5, 7, 0, 0, 9, 6, 4};
    reverseArray(arr, 11);
    for(int i=0;i<11;i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}