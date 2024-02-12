#include<iostream>
#include<stack>
using namespace std;

bool match(char A, char B)
{
    return((A=='('&&B==')')||
    (A=='{'&&B=='}')||
    (A=='['&&B==']'));
}

bool isBalanced(string str)
{
    stack<int> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[') s.push(str[i]);
        else
        {
            if(s.empty()) return false;
            else if(!match(s.top(), str[i])) return false;
            else s.pop();

        }
    }
    return s.empty();
}

int main()
{
    string str = "{}{{(())}}[]";
    cout << isBalanced(str) <<endl;
return 0;
}