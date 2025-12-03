#include <iostream>
using namespace std;

// Node structure for doubly linked list and circular linked list
struct Node {
    int data;
    Node* next;
    Node* prev; // For doubly linked list
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value, int position);
    void remove(int value);
    void search(int value);
    void display();
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
};

// Functions for DoublyLinkedList
void DoublyLinkedList::insert(int value, int position) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (position == 1) { // Insert at the head
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else { // Insert at a specific position or the end
        Node* temp = head;
        int count = 1;
        while (temp && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (!temp) { // Insert at the end
            cout << "Position exceeds length. Adding at the end.\n";
        }
        newNode->next = temp ? temp->next : nullptr;
        newNode->prev = temp;
        if (temp && temp->next) temp->next->prev = newNode;
        if (temp) temp->next = newNode;
    }
    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::remove(int value) {
    Node* temp = head;
    while (temp && temp->data != value) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Node not found.\n";
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next; // Handle head case
    delete temp;
    cout << "Node deleted successfully.\n";
}

void DoublyLinkedList::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Node found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}

void DoublyLinkedList::display() {
    Node* temp = head;
    if (!temp) {
        cout << "List is empty.\n";
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
void CircularLinkedList::insert(int value, int position) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!tail) { // Insert in an empty list
        newNode->next = newNode;
        tail = newNode;
    } else if (position == 1) { // Insert at the head
        newNode->next = tail->next;
        tail->next = newNode;
    } else { // Insert at specific position or the end
        Node* temp = tail->next;
        int count = 1;
        while (temp != tail && count < position - 1) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }
    cout << "Node inserted successfully.\n";
}

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
                if (temp == tail) tail = prev;
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

void CircularLinkedList::search(int value) {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = tail->next;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Node found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    cout << "Node not found.\n";
}

void CircularLinkedList::display() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = tail->next;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

// Main menu-driven program
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, value, position, type;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 5) break;

        cout << "Select List Type:\n1. Doubly Linked List\n2. Circular Linked List\nChoose: ";
        cin >> type;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            if (type == 1) dll.insert(value, position);
            else cll.insert(value, position);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            if (type == 1) dll.remove(value);
            else cll.remove(value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (type == 1) dll.search(value);
            else cll.search(value);
            break;
        case 4:
            if (type == 1) dll.display();
            else cll.display();
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (true);

    return 0;
}