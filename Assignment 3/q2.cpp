// Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

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

int main() {
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++) {
        push(s[i]);
    }
    while(top!=-1) {
        cout<<pop();
    }
    return 0;
}
