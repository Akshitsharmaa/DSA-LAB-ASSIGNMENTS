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

    // Function to find the middle of the linked list
    void findMiddle() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Traverse the list with slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow pointer by one step
            fast = fast->next->next;    // Move fast pointer by two steps
        }

        cout << "The middle of the linked list is: " << slow->data << endl;
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

    // Find and display the middle node
    list.findMiddle();

    return 0;
}