#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void findFirstNonRepeating(string str) {
    // Frequency map to store character counts
    unordered_map<char, int> freqMap;
    
    // Queue to store characters for checking non-repeating ones
    queue<char> q;

    for (int i = 0; i < str.length(); i++) {
        // Increment the count of the current character
        freqMap[str[i]]++;

        // Add the character to the queue if it appears for the first time
        if (freqMap[str[i]] == 1) {
            q.push(str[i]);
        }

        // Remove characters from the front of the queue that are repeating
        while (!q.empty() && freqMap[q.front()] > 1) {
            q.pop();
        }

        // If the queue is not empty, the front is the first non-repeating character
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            // If no non-repeating character exists, print -1
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    string input = "aabcbc";
    cout << "First non-repeating characters: ";
    findFirstNonRepeating(input);
    return 0;
}