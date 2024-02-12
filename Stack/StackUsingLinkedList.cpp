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

struct Stack
{
    Node *head;
    int size;
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop()
    {
        if(head==NULL) return INT_MAX;
        int r = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return r;
    }

    int peek()
    {
        if(head==NULL) return INT_MAX;
        return head->data;
    }

    int sz()
    {
        return size;
    }

    int isEmpty()
    {
        return (head==NULL);
    }
};

int main()
{
    Stack head;
    cout << head.pop() <<endl;
    head.push(2);
    head.push(22);
    head.push(222);
    cout << head.peek() <<endl;
    cout << head.pop() <<endl;
    cout << head.peek() <<endl;
    cout << head.sz() <<endl;
    cout << head.isEmpty() <<endl;
return 0;
}