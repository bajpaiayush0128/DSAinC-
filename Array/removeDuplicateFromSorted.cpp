#include<iostream>
using namespace std;

int removeDulpicate(int arr[], int n)
{
    int i=1, j;
    for (j=1;j<n;j++)
    {
        if(arr[j]!=arr[i-1])
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i;
}

int main()
{
    int arr[]={2, 2, 3, 4, 5, 5, 6, 6};

    int s = removeDulpicate(arr,8);

    for(int i=0;i<s;i++)
    {
        cout << arr[i] << " ";
    }
    
return 0;
}