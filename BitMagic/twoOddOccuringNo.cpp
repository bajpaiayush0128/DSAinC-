#include <iostream>
using namespace std;

void oddOccuring(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count % 2 != 0)
            cout << arr[i] << " ";
    }
}

void findOdd(int arr[], int n)
{
    int XOR = 0, res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    int sn = XOR & ~(XOR - 1);
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & sn) != 0)
            res1 = res1 ^ arr[i];
        else
            res2 = res2 ^ arr[i];
    }
    cout << res1 << " " << res2;
}

int main()
{
    int arr[] = {2, 3, 3, 4, 2, 5, 4, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    oddOccuring(arr, n);
    cout << endl;
    findOdd(arr, n);
    return 0;
}