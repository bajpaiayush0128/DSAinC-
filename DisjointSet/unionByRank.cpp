#include <iostream>
using namespace std;

#define n 5

int parent[n], ranks[n];

void initialize()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void unionSet(int x, int y)
{
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
        return;
    if (ranks[x_rep] < ranks[y_rep])
        parent[x_rep] = y_rep;
    else if (ranks[y_rep] < ranks[x_rep])
        parent[y_rep] = x_rep;
    else
    {
        parent[y_rep] = x_rep;
        ranks[x_rep]++;
    }
}

int main()
{

    return 0;
}