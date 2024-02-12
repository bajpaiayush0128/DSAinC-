#include<iostream>
using namespace std;

void movezeroToEnd(int arr[], int n)
{
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 0, 4, 5, 7, 0, 0, 9, 6, 4};
    movezeroToEnd(arr, 11);
    for(int i=0;i<11;i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}