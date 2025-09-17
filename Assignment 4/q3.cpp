#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    
    // If the queue has an odd number of elements, we will not be able to equally split it
    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave!" << endl;
        return;
    }
    
    // Step 1: Split the queue into two halves
    int halfSize = n / 2;
    queue<int> firstHalf, secondHalf;
    
    // Fill first half queue
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    
    // Fill second half queue
    for (int i = 0; i < halfSize; i++) {
        secondHalf.push(q.front());
        q.pop();
    }
    
    // Step 2: Interleave the elements of both halves
    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Sample input queue
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    displayQueue(q);
    
    interleaveQueue(q);
    
    cout << "Interleaved Queue: ";
    displayQueue(q);

    return 0;
}
