#include <iostream>
#include <algorithm>
using namespace std;

void unionFun(int a[], int b[], int m, int n)
{
    int c[m + n];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    for (int i = 0; i < m; i++)
        c[m + i] = b[i];
    sort(c, c + m + n);
    for (int i = 0; i < (m + n); i++)
    {
        if (i == 0 || c[i] != c[i - 1])
            cout << c[i] << " ";
    }
}

void unionFun1(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i + 1])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j + 1])
        {
            j++;
            continue;
        }
        if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i > 0 && a[i] != a[i - 1])
        {
            cout << a[i] << " ";
            i++;
        }
    }
    while (j < n)
    {
        if (j > 0 && b[j] != b[j - 1])
        {
            cout << b[j] << " ";
            j++;
        }
    }
}

int main()
{

    return 0;
}