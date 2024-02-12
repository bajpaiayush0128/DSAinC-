#include <iostream>
using namespace std;

int main()
{
    int arr[3][2] = {{10, 20},
                     {30, 40},
                     {50, 60}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << arr[i][j] << " ";
    }

    // using double pointer
    int m = 3, n = 2;
    int **arrr;
    arrr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arrr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrr[i][j] = 10;
            cout << arrr[i][j] << " ";
        }
    }
    return 0;
}