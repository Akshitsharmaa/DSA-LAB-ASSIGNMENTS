#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int value);
    bool isCircular();
    void display();
};

// Insert a node at the end of the linked list
void LinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) { // Empty list
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node inserted into the Linked List.\n";
}

// Check if the linked list is circular
bool LinkedList::isCircular() {
    if (!head) return false; // An empty list is not circular

    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return temp == head; // If we encounter the head again, it's circular
}

// Display the linked list
void LinkedList::display() {
    if (!head) {
        cout << "Linked List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == head) { // Prevent infinite loop for circular lists
            break;
        }
    }
    cout << endl;
}

// Main program
int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Check if Circular\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
            list.display();
            break;
        case 3:
            if (list.isCircular()) {
                cout << "The Linked List is circular.\n";
            } else {
                cout << "The Linked List is not circular.\n";
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
