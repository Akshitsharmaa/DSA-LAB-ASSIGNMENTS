// Develop a menu driven program demonstrating the following operations on a Stack using array: 
//(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include <iostream>
using namespace std;
#define n 5

int a[n], top=-1;

void push(int b) {
    if(top==n-1) {
        cout<<"Overflow\n";
    } else {
        top++;
        a[top]=b;
    }
}

void pop() {
    if(top==-1) {
        cout<<"Underflow\n";
    } else {
        cout<<"Popped: "<<a[top]<<endl;
        top--;
    }
}

void isEmpty() {
    if(top==-1) {
        cout<<"Stack is Empty\n";
    } else {
        cout<<"Stack is not Empty\n";
    }
}

void isFull() {
    if(top==n-1) {
        cout<<"Stack is Full\n";
    } else {
        cout<<"Stack is not Full\n";
    }
}

void display() {
    if(top==-1) {
        cout<<"Stack Empty\n";
    } else {
        for(int b=top;b>=0;b--) {
            cout<<a[b]<<" ";
        }
        cout<<endl;
    }
}

void peek() {
    if(top==-1) {
        cout<<"Stack Empty\n";
    } else {
        cout<<"Top: "<<a[top]<<endl;
    }
}

int main() {
    int b,c;
    while(true) {
        cout<<"1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin>>b;
        switch(b) {
            case 1: cin>>c; push(c); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
        }
    }
}
