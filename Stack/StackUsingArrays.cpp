#include<iostream>
using namespace std;

struct Stack
{
    int *arr;
    int cap;
    int top;

    Stack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        if(top==cap-1) cout << "\nStack is full." <<endl;
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if(top==-1) return -1;
        int r = arr[top];
        top--;
        return r;
    }

    int peek()
    {
        if(top==-1) return -1;
        return arr[top];
    }

    int size()
    {
        return (top+1);
    }

    int isEmpty()
    {
        return (top==-1);
    }
};

int main()
{
    Stack s(5);
    cout << s.pop() <<endl;
    s.push(2);
    s.push(22);
    s.push(222);
    cout << s.peek() <<endl;
    cout << s.size() <<endl;
    cout << s.isEmpty() <<endl;
return 0;
}