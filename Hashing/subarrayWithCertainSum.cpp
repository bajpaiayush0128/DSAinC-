#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool is0Subarray(int arr[], int n)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (s.find(pre_sum) != s.end())
            return true;
        if (pre_sum == 0)
            return true;
        s.insert(pre_sum);
    }
    return false;
}

bool isTargetSubaray(int arr[], int n, int target)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre_sum == target)
            return true;
        if (s.find(pre_sum - target) != s.end())
            return true;
        s.insert(pre_sum);
    }
    return false;
}

int maxSubarray(int arr[], int n, int target)
{
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == target)
            res = i + 1;
        if (m.find(pre_sum) == m.end())
            m.insert({pre_sum, i});
        if (m.find(pre_sum - target) != m.end())
            res = max(res, i - m[pre_sum - target]);
    }
    return res;
}

int eq0and1(int arr[], int n)
{
}

int maxCommonSpan(int a[], int b[], int m, int n)
{
}

int longestConsecutive(int arr[], int n)
{
}

void countDistInEveryWin(int arr, int n, int k)
{
}

// moore voting algo
void morethanNbyK(int arr[], int n, int k)
{
}

int main()
{

    return 0;
}