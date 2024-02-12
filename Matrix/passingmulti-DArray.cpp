#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &arrr) // int **arr, int m, int n , vector<int> arrr[], int m
{
    for (int i = 0; i < arrr.size(); i++)
    {
        for (int j = 0; j < arrr[i].size(); j++)
        {
            cout << arrr[i][j] << " ";
        }
    }
}

int main()
{
    int m = 3, n = 2;
    // int **arr;
    // arr = new int *[m];
    int *arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i;
            cout << arr[i][j] << " ";
        }
    }
    vector<int> arrr[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrr[i].push_back(i);
        }
    }
    // print(arrr, m);
    vector<vector<int>> arr1;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(i);
        }
        arr1.push_back(v);
    }
    print(arr1);
    return 0;
}