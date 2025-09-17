// Write a program that checks if an expression has balanced parentheses

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
    if(top==-1) {
        return '\0';
    } else {
        char b=a[top];
        top--;
        return b;
    }
}

bool isBalanced(string s) {
    for(int i=0;i<s.length();i++) {
        char b=s[i];
        if(b=='(' || b=='{' || b=='[') {
            push(b);
        } else if(b==')' || b=='}' || b==']') {
            if(top==-1) return false;
            char c=pop();
            if((b==')' && c!='(') || (b=='}' && c!='{') || (b==']' && c!='[')) {
                return false;
            }
        }
    }
    return (top==-1);
}

int main() {
    string s;
    cin>>s;
    if(isBalanced(s)) {
        cout<<"Balanced\n";
    } else {
        cout<<"Not Balanced\n";
    }
    return 0;
}
