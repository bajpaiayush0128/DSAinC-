#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // multiply array elements by -1 and while printing do like (-pq.top()), to create a minHeap
    int arr[] = {10, 15, 5};
    priority_queue<int> pq(arr, arr + 3);
    // priority_queue<int> pq;
    // priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size() << endl;
    cout << pq.top() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}