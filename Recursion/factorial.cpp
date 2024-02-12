#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0||n==1) return 1;
    return n*factorial(n-1);
}

int factorial_tail(int n, int k)
{
    if(n==0||n==1) return k;
    return factorial_tail(n-1, k*n);
}

int main()
{
    int n = 5;
    int value = factorial(n);
    cout << value;
return 0;
}