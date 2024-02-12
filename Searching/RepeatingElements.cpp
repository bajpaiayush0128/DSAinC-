#include <iostream>
using namespace std;

int repeating(int arr[], int n)
{
    bool visited[n - 1] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[arr[i]])
            return arr[i];
        visited[arr[i]] = true;
    }
    return -1;
}

// this is if array elements start with 1, if they start with 0, add 1 everywhere you change slow and fast pointers, return slow-1 are ans
int findRep(int arr[], int n)
{
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return arr[slow];
}

int main()
{

    return 0;
}