#include <iostream>
#include <queue>
using namespace std;

void printKClosest(int arr[], int n, int k, int x)
{
    bool visited[n] = {false};
    for (int i = 0; i < k; i++)
    {
        int min_diff = INT_MAX;
        int min_diff_idx;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && abs(arr[j] - x) <= min_diff) // abs is absolute diff
            {
                min_diff = abs(arr[j] - x);
                min_diff_idx = j;
            }
        }
        cout << arr[min_diff_idx] << " ";
        visited[min_diff_idx] = true;
    }
}

void kClosest(int arr[], int n, int k, int x)
{
    // priority_queue<int> pq;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), i});
    }
    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);
        if (pq.top().first > diff)
        {
            pq.pop();
            pq.push({diff, i});
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {-10, -50, 20, 17, 80};
    int X = 20, K = 2;
    int N = sizeof(arr) / sizeof(arr[0]);

    printKClosest(arr, N, K, X);
    cout << endl;
    kClosest(arr, N, K, X);
    return 0;
}