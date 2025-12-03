#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(char value);
    bool isPalindrome();
    void display();
};

// Insert a character at the end of the doubly linked list
void DoublyLinkedList::insert(char value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) { // Empty list
        head = tail = newNode;
    } else { // Append at the end
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Character inserted into Doubly Linked List.\n";
}

// Check if the doubly linked list is a palindrome
bool DoublyLinkedList::isPalindrome() {
    if (!head || !head->next) return true; // Empty list or single node is always a palindrome

    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) { // Move pointers inward
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }

    return true; // All characters matched
}

// Display the doubly linked list
void DoublyLinkedList::display() {
    if (!head) {
        cout << "Doubly Linked List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main program
int main() {
    DoublyLinkedList dll;
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Character\n";
        cout << "2. Display List\n";
        cout << "3. Check if Palindrome\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a character to insert: ";
            cin >> value;
            dll.insert(value);
            break;
        case 2:
            dll.display();
            break;
        case 3:
            if (dll.isPalindrome()) {
                cout << "The Doubly Linked List is a palindrome.\n";
            } else {
                cout << "The Doubly Linked List is not a palindrome.\n";
            }
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
