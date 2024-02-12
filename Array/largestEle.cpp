#include<iostream>
using namespace std;

int getLargest(int arr[], int n)
{
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[temp]) temp = i;
    }
    return temp;
}

int main()
{
    int arr[] = {1, 2, 3, 40, 7, 9, 13};
    int largest = getLargest(arr, 7);
    cout << "Largest element in array is at index: "<< largest;
return 0;
}