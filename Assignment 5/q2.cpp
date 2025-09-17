#include <iostream>
using namespace std;

// Node structure to represent each element in the linked list
struct Node {
    int data;
    Node* next;
};

// Class to represent Singly Linked List
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
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
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

    // Function to count occurrences of a key in the list
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    // Function to delete all occurrences of a specific key
    void deleteAllOccurrences(int key) {
        // Handle the case where the head itself is the key
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Handle the case where the key occurs after the head
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
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
    int value, key;

    // Insert some values into the linked list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original Linked List: ";
    list.displayList();

    // Ask for the key to search and delete occurrences
    cout << "Enter the key to count and delete: ";
    cin >> key;

    // Count occurrences of the key in the list
    int occurrences = list.countOccurrences(key);
    cout << "Number of occurrences of " << key << ": " << occurrences << endl;

    // Delete all occurrences of the key
    list.deleteAllOccurrences(key);

    cout << "Updated Linked List after deleting all occurrences of " << key << ": ";
    list.displayList();

    return 0;
}
