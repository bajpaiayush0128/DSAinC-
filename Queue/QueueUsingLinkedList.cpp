#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node *front, *rear;
    int size;
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enque(int x)
    {
        Node *temp = new Node(x);
        size++;
        if(front==NULL) front = rear = temp;
        rear->next = temp;
        rear = temp;
    }

    void deque()
    {
        if(front==NULL) return;
        size--;
        Node *temp = front;
        front = front->next;
        if(front==NULL) rear = NULL;
        delete temp;
    }

    int getFront()
    {
        if(front==NULL) return -1;
        return front->data;
    }

    int getBack()
    {
        if(rear==NULL) return -1;
        return rear->data;
    }

    int isEmpty()
    {
        if(front==NULL) return true;
        return false;
    }
};

int main()
{
    Queue q;
    q.enque(2);
    q.enque(3);
    q.enque(4);
    cout << q.getFront() << " " << q.getBack() <<endl;
    q.deque();
    cout << q.getFront() << " " << q.getBack() <<endl;

    while(q.isEmpty()==false)
    {
        cout << q.getFront() << " " << q.getBack() <<endl;
        q.deque();
    }
return 0;
}