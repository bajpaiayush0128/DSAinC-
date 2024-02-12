#include <iostream>
using namespace std;

#define m 3
#define n 2

void printSnake(int mat[m][n])
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
}

int main()
{
    int arr[3][2] = {{10, 20},
                     {30, 40},
                     {50, 60}};
    printSnake(arr);
    return 0;
}