#include <iostream>
using namespace std;

int main()
{
    int m, sum = 0, count = 0;
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "enter your sum money: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        while (sum <= m)
            sum += arr[i];
    }
    cout << "\nsum is: " << sum;
    if (sum == m)
        count++;

    cout << "\ncount is: " << count;
    return 0;
}