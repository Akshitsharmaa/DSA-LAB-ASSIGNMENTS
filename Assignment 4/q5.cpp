#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    // Push operation
    void push(int x) {
        // Enqueue x to q1
        q1.push(x);
        
        // Move all elements from q1 to q2 so that the last element pushed is at the front of q1
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 to make q1 hold the current stack
        swap(q1, q2);
    }

    // Pop operation
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        int poppedElement = q1.front();
        q1.pop();
        return poppedElement;
    }

    // Top operation (Peek)
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top of the stack: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top of the stack after pop: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
