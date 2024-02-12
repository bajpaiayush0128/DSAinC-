#include <iostream>
using namespace std;
#define N 100

class Fib
{
public:
    const int Nil = -1;
    int memo[N + 1];
    void initialize()
    {
        for (int i = 0; i <= N; i++)
            memo[i] = Nil;
    }

    int fib(int n)
    {
        // for (int i = 0; i <= N; i++)
        //     memo[i] = Nil;
        // fill_n(memo, N + 1, Nil);
        if (memo[n] == Nil)
        {
            int res;
            if (n == 0 || n == 1)
                res = n;
            else
                res = fib(n - 1) + fib(n - 2);
            memo[n] = res;
        }
        return memo[n];
    }
};

int main()
{
    int n = 6;
    Fib f;
    cout << f.fib(n);
    return 0;
}