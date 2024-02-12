#include <iostream>
using namespace std;

#define m 3
#define n 3

void boundaryTraversal(int mat[m][n])
{
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
            cout << mat[0][i] << " ";
    }
    else if (n == 1)
    {
        for (int i = 0; i < m; i++)
            cout << mat[i][0] << " ";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << mat[0][i] << " ";
        for (int i = 1; i < m; i++)
            cout << mat[i][n - i] << " ";
        for (int i = n - 2; i >= 0; i--)
            cout << mat[m - 1][i] << " ";
        for (int i = m - 2; i >= 1; i--)
            cout << mat[i][0] << " ";
    }
}

int main()
{
    int arr[3][3] = {{10, 20, 70},
                     {30, 40, 80},
                     {50, 60, 90}};
    boundaryTraversal(arr);
    return 0;
}