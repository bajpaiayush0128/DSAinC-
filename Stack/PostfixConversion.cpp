// #include<bits/stdc++.h>
// using namespace std;

// bool isOperand(char opr){
//     if(opr=='+' || opr=='-' || opr=='*' || opr=='/')
//     return false;
//     return true;
// }

// int pre(char x){
//     if(x=='*' || x=='/')
//     return 2;
//     else if(x=='+' || x=='-')
//     return 1;
//     return -1;
// }

// char* infixToPostfix(const char* infix){
//     stack<char> s;
//     s.push('?');
//     int i=0, j=0;
//     char* postfix=new char(strlen(infix)+1);
    
//     while(infix[i]!='\0'){
//         if(isOperand(infix[i])){
//             postfix[j++]=infix[i++];
//         }else{
//             while(s.top()!='?' && pre(infix[i])<=pre(s.top()))
//             {
//                 postfix[j++]=s.top();
//                 s.pop();
//             }
//                 s.push(infix[i++]);
//         }
//     }

//     while(s.top()!='?'){
//         postfix[j++]=s.top();
//         s.pop();
//     }

//     postfix[j]='\0';

//     return postfix;
// }

// int main(){
//     // if we are not writing const then following error is there
//     // Parenthesis_matching.cpp:70:15: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] char exp="((a+b)(c-d)))";

//     const char *exp="a*b+c/d-e";
//     char* postfix=infixToPostfix(exp);
//     cout<<postfix;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// // Implementing Stack using array 
// template<class T>
// class Stack{
//     int size;
//     int top;
//     T *arr;

//     public:

//     Stack(){
//         size=5;
//         top=-1;
//         arr= new T(size);
//     }

//     Stack(int size){
//         this->size=size;
//         top=-1;
//         arr= new T(size);
//     }

//     bool isFull(){
//         if(top==size-1) return 1;
//         return 0;
//     }

//     bool isEmpty(){
//         if(top==-1) return 1;
//         return 0;
//     }

//     T stackTop(){
//         if(isFull()) cout<<"Stack is Full"<<endl;
//         if(isEmpty()) return -1;
//         return arr[top];
//     }

//     void push(T x){
//         if(isFull()) cout<<"Stack is Full"<<endl;
//         else{
//             arr[++top]=x;
//         }
//     }

//     T pop(){
//         char x=-1;
//         if(isEmpty()) return -1;
//         else{
//             x=arr[top--];
//         return x;
//         }
//     }
//     void display(){
//         for(int i=top; i>=0;i--) cout<<arr[i]<<" ";
//         cout<<endl;
//     }
    
//     bool isOperand(char opr){
//         if(opr=='+' || opr=='-' || opr=='*' || opr=='/')
//         return false;
//         return true;
//     }

//     int pre(char x){
//         if(x=='+' || x=='-')
//         return 1;
//         else if(x=='*' || x=='/')
//         return 2;
//         return -1;
//     }

//     char* infixToPostfix(const char* infix, Stack<T> s){
//         int i=0, j=0;
//         s.push('#');
//         char* postfix=new char(strlen(infix)+1);
        
//         while(infix[i]!='\0'){
//             if(s.isOperand(infix[i])){
//                 postfix[j++]=infix[i++];
//             }else{
//                 if((s.pre(infix[i]))>(s.pre(s.stackTop())))
//                     s.push(infix[i++]);
//                 else if(s.stackTop()!='#'){
//                     postfix[j++]=s.pop();
//                 }
//             }
//         }

//         while(s.stackTop()!='#'){
//             postfix[j++]=s.pop();
//         }

//         postfix[j]='\0';

//         return postfix;
//     }
// };

// int main(){
//     // if we are not writing const then following error is there
//     // Parenthesis_matching.cpp:70:15: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] char exp="((a+b)(c-d)))";

//     const char *exp="a*b+c-d/e";
//     Stack<char> s(strlen(exp));
//     char* postfix=s.infixToPostfix(exp,s);
//     cout<<postfix;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

bool isOperand(char opr){
    if(opr=='+' || opr=='-' || opr=='*' || opr=='/')
    return false;
    return true;
}

int pre(char x){
    if(x=='+' || x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 2;
    return -1;
}

char* infixToPostfix(const char* infix){
    stack<char> s;
    s.push('?');
    int i=0, j=0;
    char* postfix=new char(strlen(infix)+1);
    // ((a*(b+c)-d)/e)
    // abc+*d-e/
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            if(infix[i]=='(')
            s.push(infix[i++]);
            else if(infix[i]==')'){
                i++;
                while(s.top()!='?' && s.top()!='('){
                        postfix[j++]=s.top();
                        s.pop();
                }
                if(s.top()=='(') s.pop();
            }
            else
            {
                postfix[j++]=infix[i++];
            }
        }else{
            if(s.top()!='?' && pre(infix[i])<=pre(s.top()))
            {
                postfix[j++]=s.top();
                s.pop();
            }else
                s.push(infix[i++]);
        }
    }

    while(s.top()!='?'){
        postfix[j++]=s.top();
        s.pop();
    }

    postfix[j]='\0';

    return postfix;
}

int main(){
    // if we are not writing const then following error is there
    // Parenthesis_matching.cpp:70:15: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] char exp="((a+b)(c-d)))";
//ab*c+de/-
    const char *exp="((A*(b+C)-d)/e)";
    char* postfix=infixToPostfix(exp);
    cout<<postfix;
    return 0;
}