#include<iostream>
using namespace std;

struct Deque
{
    int *arr;
    int front, cap, size;
    Deque(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }
};

bool isFull()
{
    return (size==cap);
}

bool isEmpty()
{
    return (size==0);
}

int getFront()
{
    if(isEmpty()) return;
    return front;
}

int getRear()
{
    if(isEmpty()) return;
    return (front+size-1)%cap;
}

void insertFront(int data)
{
    if(isFull()) return;
    front = (front+cap-1)%cap;
    arr[front] = data;
    size++;
}

void deleteFront()
{
    if(isEmpty()) return;
    front = (front+1)%cap;
    size--;
}

void insertRear(int data)
{
    if(isFull()) return;
    int rear = (front+size)%cap;
    arr[rear] = data;
    size++;
}

void deleteRear()
{
    if(isEmpty()) return;
    size--;
}



int main()
{
    
return 0;
}