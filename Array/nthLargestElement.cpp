#include<iostream>
using namespace std;

int nthLargest(int arr[], int n)
{
    int res=-1, largest=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(res==-1||arr[i]>arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[] = {9, 8, 6, 5, 3};
    int nth = nthLargest(arr, 5);
    cout << "2nd Largest element is at index: "<<nth<<endl;
return 0;
}