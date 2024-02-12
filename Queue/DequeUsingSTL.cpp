#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_front(5);
    dq.push_front(10);
    dq.push_front(15);
    dq.push_back(15);
    for(auto x:dq) cout << x << " ";
    cout << "\n" << dq.front() << " " << dq.back() << endl;

    auto it = dq.begin();
    it++;
    // insert and erase are of order O(n).
    dq.insert(it, 20);
    for(auto x:dq) cout << x << " ";
    dq.pop_front();
    dq.pop_back();
    cout << '\n' << dq.size() << endl;
return 0;
}