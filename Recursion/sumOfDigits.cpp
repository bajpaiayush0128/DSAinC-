#include<iostream>
using namespace std;

int sumOfDigits(int n)
{
    if(n<10) return n;
    return sumOfDigits(n/10)+n%10;

}

int main()
{
    int n = 345;
    cout << sumOfDigits(n);
return 0;
}