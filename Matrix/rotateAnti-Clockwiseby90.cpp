#include <iostream>
using namespace std;

#define n 3

void rotate90(int mat[n][n])
{
    int temp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            temp[n - j - 1][i] = mat[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
    }
}

void rotateBy90(int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1;
        while (low < high)
        {
            swap(mat[low][i], mat[high][i]);
            low++;
            high--;
        }
    }
}

int main()
{
    return 0;
}