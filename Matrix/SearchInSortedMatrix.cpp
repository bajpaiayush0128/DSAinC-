// matrix is row-wise and column-wise sorted

#include <iostream>
using namespace std;

#define m 3
#define n 3

void search(int mat[m][n], int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == x)
            {
                cout << "Found at: " << i << ", " << j;
                return;
            }
        }
    }
    cout << "Not found";
}

void search1(int mat[m][n], int x)
{
    if (x < mat[0][0])
    {
        cout << "Not found";
        return;
    }
    else if (x > mat[m - 1][n - 1])
    {
        cout << "Not found";
        return;
    }
    else
    {
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (mat[i][j] == x)
            {
                cout << "Found at: " << i << ", " << j;
                return;
            }
            else if (mat[i][j] > x)
                j--;
            else
                i++;
        }
        cout << "Not found";
    }
}

int main()
{
    int arr[3][3] = {{10, 20, 70},
                     {30, 40, 80},
                     {50, 60, 90}};
    search1(arr, 40);
    return 0;
}