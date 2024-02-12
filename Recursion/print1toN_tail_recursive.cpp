#include<iostream>
using namespace std;

void print1toN(int n, int k)
{
    if(n==0) return;
    cout << k << " ";
    print1toN(n-1, k+1);
}

int main()
{
    int n = 4;
    print1toN(n, 1);
return 0;
}