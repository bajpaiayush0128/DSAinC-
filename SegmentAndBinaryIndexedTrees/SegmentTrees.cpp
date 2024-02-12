// size of array for segment trees = 2*2^[log2 n] - 1
// its upper bound is 4n
#include <iostream>
using namespace std;

int tree[80];
int arr[20];
// initial values ss(start range) = 0, se(end range) = n-1, si=0
int constructST(int ss, int se, int si)
{
    if (ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    tree[si] = constructST(ss, mid, 2 * si + 1) + constructST(mid + 1, se, 2 * si + 1);
    return tree[si];
}

// qe and qs are end and start of query range you want sum of
int getSumRec(int qs, int qe, int ss, int se, int si)
{
    if (se < qs || ss > qe)
        return 0;
    if (qs <= ss && qe >= se)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSumRec(qs, qe, ss, mid, 2 * si + 1) + getSumRec(qs, qe, mid + 1, se, 2 * si + 2);
}

void updateRec(int ss, int se, int i, int si, int diff)
{
    if (i < ss || i > se)
        return;
    tree[si] = tree[si] + diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        updateRec(ss, mid, i, 2 * si + 1, diff);
        updateRec(mid + 1, se, i, 2 * si + 2, diff);
    }
}

int main()
{
    int arr[] = {1, 20, 30, 40};
    int new_val = 25, i = 1;
    int diff = new_val - arr[i];
    updateRec(0, 3, 1, 0, 5);
    return 0;
}