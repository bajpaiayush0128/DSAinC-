#include <iostream>
using namespace std;

void getSubsets(string &str, string curr = "", int index = 0)
{
    if (index == str.length())
    {
        cout << curr << " ";
        return;
    }
    getSubsets(str, curr, index + 1);
    getSubsets(str, curr + str[index], index + 1);
}

int main()
{
    string s = "123";
    getSubsets(s);
    return 0;
}