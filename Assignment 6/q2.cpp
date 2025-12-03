#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* tail;
public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int value, int position);
    void remove(int value);
    void search(int value);
    void display();
    void displayWithHeadRepeat(); // New function to display nodes with head repeated
};

// Insert a node at a specific position in the circular linked list
void CircularLinkedList::insert(int value, int position) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) { // Insert in an empty list
        newNode->next = newNode;
        tail = newNode;
    } else if (position == 1) { // Insert at the head
        newNode->next = tail->next;
        tail->next = newNode;
    } else { // Insert at a specific position or the end
        Node* temp = tail->next;
        int count = 1;
        while (temp != tail && count < position - 1) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode; // Update tail if inserted at the end
    }
    cout << "Node inserted successfully.\n";
}

// Remove a specific node by value
void CircularLinkedList::remove(int value) {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail->next, *prev = tail;
    do {
        if (temp->data == value) {
            if (temp == tail && temp->next == tail) { // Single node case
                tail = nullptr;
            } else {
                prev->next = temp->next;
                if (temp == tail) tail = prev; // Update tail if last node is removed
            }
            delete temp;
            cout << "Node deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != tail->next);
    cout << "Node not found.\n";
}

// Search for a specific node by value
void CircularLinkedList::search(int value) {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail->next;
    int position = 1;
    do {
        if (temp->data == value) {
            cout << "Node found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != tail->next);
    cout << "Node not found.\n";
}

// Display all nodes in the circular linked list
void CircularLinkedList::display() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail->next; // Start from the head
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Stop when we complete one cycle
    cout << endl;
}

// Display all nodes and repeat the head node's value at the end
void CircularLinkedList::displayWithHeadRepeat() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail->next; // Start from the head
    cout << "Circular Linked List (with head repeated): ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Stop when we complete one cycle
    cout << tail->next->data; // Print the head's value again
    cout << endl;
}

// Main menu-driven program
int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            cll.insert(value, position);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            cll.remove(value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            cll.search(value);
            break;
        case 4:
            cout << "Repeat head node at the end? (1 = Yes, 0 = No): ";
            int repeatHead;
            cin >> repeatHead;
            if (repeatHead) cll.displayWithHeadRepeat();
            else cll.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}