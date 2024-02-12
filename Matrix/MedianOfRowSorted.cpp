#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int median(int mat[][MAX], int r, int c)
{
    int min = mat[0][0], max = mat[0][c - 1];
    for (int i = 0; i < r; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];
        if (mat[i][c - 1] > max)
            max = mat[i][c - 1];
    }
    int medianPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int midPos = 0;

        for (int i = 0; i < r; ++i)
            midPos += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
        if (midPos < medianPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    int r = 3, c = 3;
    int arr[][MAX] = {{1, 3, 5},
                      {2, 6, 9},
                      {3, 6, 9}};
    cout << "Median is: " << median(arr, r, c);
    return 0;
}