#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.size() << endl;
    cout << q.front() << " " << q.back() <<endl;
    q.pop();
    cout << "after one pop..." <<endl;
    cout << q.front() << " " << q.back() <<endl;
    cout << "testing traversal..." <<endl;

    while(q.empty()==false)
    {
        cout << q.front() << " " << q.back() <<endl;
        q.pop();
    }
return 0;
}