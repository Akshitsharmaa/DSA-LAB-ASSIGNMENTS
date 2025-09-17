// Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
#include <string>
using namespace std;
#define n 100

char a[n];
int top=-1;

void push(char b) {
    if(top<n-1) {
        top++;
        a[top]=b;
    }
}

char pop() {
    if(top==-1) return '\0';
    char b=a[top];
    top--;
    return b;
}

char peek() {
    if(top==-1) return '\0';
    return a[top];
}

int prec(char b) {
    if(b=='^') return 3;
    if(b=='*' || b=='/') return 2;
    if(b=='+' || b=='-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    string res="";
    for(int i=0;i<s.length();i++) {
        char b=s[i];
        if((b>='a' && b<='z') || (b>='A' && b<='Z') || (b>='0' && b<='9')) {
            res+=b;
        }
        else if(b=='(') {
            push(b);
        }
        else if(b==')') {
            while(top!=-1 && peek()!='(') {
                res+=pop();
            }
            pop();
        }
        else {
            while(top!=-1 && prec(peek())>=prec(b)) {
                res+=pop();
            }
            push(b);
        }
    }
    while(top!=-1) {
        res+=pop();
    }
    return res;
}

int main() {
    string s;
    cin>>s;
    cout<<infixToPostfix(s)<<endl;
    return 0;
}
