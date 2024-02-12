#include <iostream>
#include <queue>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k + 1; i < n; i++)
    {
        if (arr[i] < pq.top())
            continue;
        pq.pop();
        pq.push(arr[i]);
    }
}

int main()
{

    return 0;
}