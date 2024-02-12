#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int insert(int arr[], int n, int x, int capacity, int pos)
{
    // if(n==capacity) return n;
    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[idx] = x;
    return n + 1;
}

int deleteEle(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }
    if (i == n)
        return n;
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    return (n - 1);
}

int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n]{};
    cout << "How many elements you want to insert?";
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
    cout << "Elements of array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // searching the element
    int searched = search(arr, n, 7);
    cout << "\nSearched result is at index: " << searched;

    // inserting element in array
    int inserted = insert(arr, n, 7, 7, 3);
    cout << "\nElements in array are till index: " << inserted;
    cout << "\nElements after insertion are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // deleting an element
    int deleted = deleteEle(arr, n, 7);
    cout << "\nAfter deleting no of elements in array: " << deleted;
    cout << "\nElements after deletion are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}