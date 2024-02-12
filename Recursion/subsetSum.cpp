#include <iostream>
using namespace std;

int subsets(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;
    return subsets(arr, n - 1, sum) + subsets(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int arr[] = {10, 20, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 25;
    cout << "No of subsets are: " << subsets(arr, n, sum);
    return 0;
}