#include<iostream>
using namespace std;

void leftRotateby1(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1] = temp;
}

int main()
{
    int arr[] = {1, 0, 0, 4, 5, 7, 0, 0, 9, 6, 4};
    leftRotateby1(arr, 11);
    for(int i=0;i<11;i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}