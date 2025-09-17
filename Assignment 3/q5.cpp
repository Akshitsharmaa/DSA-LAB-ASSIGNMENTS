// Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define n 100

int a[n];
int top=-1;

void push(int b) {
    if(top<n-1) {
        top++;
        a[top]=b;
    }
}

int pop() {
    if(top==-1) return -1;
    int b=a[top];
    top--;
    return b;
}

int evalPostfix(string s) {
    for(int i=0;i<s.length();i++) {
        char b=s[i];
        if(b>='0' && b<='9') {
            push(b-'0');
        } else {
            int x=pop();
            int y=pop();
            if(b=='+') push(y+x);
            else if(b=='-') push(y-x);
            else if(b=='*') push(y*x);
            else if(b=='/') push(y/x);
            else if(b=='^') push(pow(y,x));
        }
    }
    return pop();
}

int main() {
    string s;
    cin>>s;
    cout<<evalPostfix(s)<<endl;
    return 0;
}
