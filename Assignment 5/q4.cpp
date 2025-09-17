#include <iostream>
using namespace std;

// Node structure to represent each element in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class to represent the Singly Linked List
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // Save the next node
            current->next = previous;  // Reverse the current node's pointer
            previous = current;  // Move previous and current one step forward
            current = next;
        }

        head = previous;  // After the loop, previous will be the new head
    }

    // Function to display the list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    
    // Insert some values into the linked list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Original Linked List: ";
    list.displayList();

    // Reverse the linked list
    list.reverse();

    cout << "Reversed Linked List: ";
    list.displayList();

    return 0;
}
