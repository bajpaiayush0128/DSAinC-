#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Triplet
{
    int val, arrPos, valPos;
    Triplet(int v, int apos, int vpos)
    {
        val = v;
        arrPos = apos;
        valPos = vpos;
    }
};

struct MyCmp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};

vector<int> mergeArr(vector<vector<int>> &arr)
{
    vector<int> res;
    priority_queue<Triplet, vector<Triplet>, MyCmp> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    while (!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap = curr.arrPos, vp = curr.valPos;
        if (vp + 1 < arr[ap].size())
        {
            Triplet t(arr[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }
    return res;
}

int main()
{

    return 0;
}