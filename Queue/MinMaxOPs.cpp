// all operation in O(1)
#include<iostream>
#include<deque>
using namespace std;

struct Deque
{
    deque<int> dq;
    void insertMin(int data)
    {
        dq.push_front(data);
    }
    void insertMax(int data)
    {
        dq.push_back(data);
    }
    int getMin()
    {
        return dq.front();
    }
    int getMax()
    {
        return dq.back();
    }
    int extractMin()
    {
        return dq.pop_front();
    }
    int extractMax()
    {
        return dq.pop_back();
    }
};

int main()
{
    
return 0;
}