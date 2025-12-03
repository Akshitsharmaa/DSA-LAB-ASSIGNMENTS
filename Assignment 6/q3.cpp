#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value);
    int size();
    void display();
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* tail;
public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int value);
    int size();
    void display();
};

// Functions for DoublyLinkedList
void DoublyLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) { // Empty list
        head = newNode;
    } else { // Insert at the end
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Node inserted into Doubly Linked List.\n";
}

int DoublyLinkedList::size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void DoublyLinkedList::display() {
    Node* temp = head;
    if (!temp) {
        cout << "Doubly Linked List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Functions for CircularLinkedList
void CircularLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) { // Empty list
        newNode->next = newNode;
        tail = newNode;
    } else { // Insert at the end
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Node inserted into Circular Linked List.\n";
}

int CircularLinkedList::size() {
    if (!tail) return 0;

    int count = 0;
    Node* temp = tail->next; // Start from head
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next); // Loop until back to head
    return count;
}

void CircularLinkedList::display() {
    if (!tail) {
        cout << "Circular Linked List is empty.\n";
        return;
    }
    Node* temp = tail->next; // Start from head
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

// Main program
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, type, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Find Size of List\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 4) break;

        cout << "Select List Type:\n1. Doubly Linked List\n2. Circular Linked List\nChoose: ";
        cin >> type;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            if (type == 1) dll.insert(value);
            else cll.insert(value);
            break;
        case 2:
            if (type == 1) dll.display();
            else cll.display();
            break;
        case 3:
            if (type == 1) {
                cout << "Size of Doubly Linked List: " << dll.size() << endl;
            } else {
                cout << "Size of Circular Linked List: " << cll.size() << endl;
            }
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (true);

    cout << "Exiting program.\n";
    return 0;
}
