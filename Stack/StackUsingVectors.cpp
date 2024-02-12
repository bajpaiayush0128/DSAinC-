#include<iostream>
#include<vector>
using namespace std;

struct Stack
{
    vector<int> v;

    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int r = v.back();
        v.pop_back();
        return r;
    }

    int peek()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }
};

int main()
{
    Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
return 0;
}