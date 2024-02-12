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
    for (int i = 0; i < n; i++)
        parent[i] = i;
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void unionSet(int x, int y)
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
        return;
    parent[y_rep] = x_rep;
}

int main()
{
    unionSet(2, 3);
    unionSet(1, 4);
    unionSet(4, 3);
    cout << "Set is: " << find(2);
    cout << "\nSet is: " << find(1);
    return 0;
}