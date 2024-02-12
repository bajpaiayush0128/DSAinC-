#include<iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    for(int i =0;i<n;i++)
    {
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    bool xyz = isSorted(arr, 6);
    cout << "Is sorted: "<<xyz<<endl;
    
    return 0;
}