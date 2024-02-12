#include <iostream>
using namespace std;

#define n 5

int parent[n];

void initialize()
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionSet(int x, int y)
{
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
        return;
    parent[y_rep] = x_rep;
}

int main()
{

    return 0;
}