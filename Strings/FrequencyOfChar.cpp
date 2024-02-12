#include <iostream>
using namespace std;

int main()
{
    // c_str can be used to convert string into c-type string
    // getline(cin, str, 'a') is used for input string with spaces, 'a' is just extra parameter to tell the end of input string
    string str = "thisismyworld";
    int count[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            cout << (char)(i + 'a') << " " << count[i] << endl;
    }
    return 0;
}