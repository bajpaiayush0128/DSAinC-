#include<iostream>
using namespace std;

struct Queue
{
    int size, cap, front, *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        front = 0;
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
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[size] = x;
        size++;
    }

    void deque()
    {
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }

    int getFront()
    {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear()
    {
        if(isEmpty()) return -1;
        return arr[(front+size-1)%cap];
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