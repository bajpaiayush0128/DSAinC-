#include<iostream>
using namespace std;

struct Queue
{
    int size, cap, *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    bool isFull()
    {
        return (size==cap);
    }

    bool isEmpty()
    {
        return (size==0);
    }

    void enque(int x)
    {
        if(isFull()) return;
        arr[size] = x;
        size++;
    }

    void deque()
    {
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++) arr[i] = arr[i+1];
        size--;
    }

    int getFront()
    {
        if(isEmpty()) return -1;
        return arr[0];
    }

    int getRear()
    {
        if(isEmpty()) return -1;
        return arr[size-1];
    }
};

int main()
{
    Queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    cout << q.isEmpty() <<endl;
    cout << q.isFull() <<endl;
    cout << q.getFront() <<endl;
    cout << q.getRear() <<endl;
    q.deque();
    cout << q.getFront() <<endl;
    cout << q.getRear() <<endl;
return 0;
}