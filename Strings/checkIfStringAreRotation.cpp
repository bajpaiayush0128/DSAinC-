#include <iostream>
using namespace std;

bool areRoatations(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    return ((s1 + s1).find(s2) != string::npos);
}

int main()
{

    return 0;
}