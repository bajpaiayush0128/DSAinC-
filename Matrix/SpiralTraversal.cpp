#include <iostream>
using namespace std;

#define m 3
#define n 3

void printSpiral(int mat[m][n])
{
    int top = 0, left = 0, bottom = m - 1, right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}

int main()
{
    int arr[3][3] = {{10, 20, 70},
                     {30, 40, 80},
                     {50, 60, 90}};
    printSpiral(arr);

    return 0;
}