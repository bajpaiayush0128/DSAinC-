#include <iostream>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
        return 1 + longestCommonSubsequence(s1, s2, m - 1, n - 1);
    else
    {
        max(longestCommonSubsequence(s1, s2, m - 1, n), longestCommonSubsequence(s1, s2, m, n - 1));
    }
}

int lcs(string s1, string s2, int m, int n)
{
    int memo[m + 1][n + 1];
    if (memo[m][n] != -1)
        return memo[m][n];
    if (m == 0 || n == 0)
        memo[m][n] = 0;
    else
    {
        if (s1[m - 1] == s2[n - 1])
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        else
            memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
    cout << "\nfsdf" << memo[m][n] << "fsdf" << endl;
    return memo[m][n];
}

int main()
{

    string s1 = "abcdefghijkl";
    string s2 = "abcdefghijkl";
    int m = s1.length();
    int n = s2.length();

    cout << "Longest common subsequence: " << longestCommonSubsequence(s1, s2, m, n);
    cout << "Longest common subsequence: " << lcs(s1, s2, 0, 0);

    return 0;
}