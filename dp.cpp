#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int count = 0;
const int m = 4;

int paths(int i, int j, int arr[m][m], int n)
{
    // if (arr[i][j] == 0)
    // {
    //     paths(i, j + 1, arr, n);
    //     paths(i + 1, j, arr, n);
    // }
    // if (i == n && j == n)
    //     count++;
    // return count;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 1)
            arr[i][0] = 1;
        else
            break;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[0][i] == 1)
            arr[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 0)
                continue;

            if (arr[i - 1][j] > 1)
                arr[i][j] = (arr[i][j] + arr[i - 1][j]);

            if (arr[i][j - 1] > 1)
                arr[i][j] = (arr[i][j] + arr[i][j - 1]);
        }
    }
    return (arr[n - 1][n - 1] > 0) ? arr[n - 1][n - 1] : 0;
}

int main()
{
    int n, e, count;
    // cout << "Enter number of rows: ";
    // cin >> n;
    int arr[4][4];
    cout << "Enter elements of array(Use only 0 and 1): ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> e;
            arr[i][j] = e;
        }
    }
    cout << "Matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "count is: " << endl;
    cout << paths(0, 0, arr, 4);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[i][j] == 0)
    //             break;
    //         cout << i << " " << j << endl;
    //     }
    // }

    return 0;
}

// 1 1 0 1
// 1 1 1 0
// 1 0 0 1
// 1 1 1 1