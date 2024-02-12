#include <iostream>
using namespace std;

#define n 3

void transpose(int mat[n][n])
{
    int temp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            temp[i][j] = mat[j][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
    }
}

void traspose1(int mat[n][n]) // since digonals remain same
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

int main()
{

    return 0;
}