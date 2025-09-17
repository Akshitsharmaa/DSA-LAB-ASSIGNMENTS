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

    // Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end
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

    // Insertion before or after a specific node
    void insertBeforeAfter(int target, int value, bool insertAfter) {
        Node* temp = head;

        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (insertAfter) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            newNode->next = temp;
            if (temp == head) {
                head = newNode;
            } else {
                Node* prev = head;
                while (prev->next != temp) {
                    prev = prev->next;
                }
                prev->next = newNode;
            }
        }
    }

    // Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Deletion of a specific node
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node with value " << value << " not found!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Search for a node and display its position from the head
    void searchNode(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Node " << value << " not found!" << endl;
    }

    // Display all nodes
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
    int choice, value, target;
    bool insertAfter;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at the Beginning\n";
        cout << "2. Insert at the End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from the Beginning\n";
        cout << "5. Delete from the End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display All Nodes\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Insert before (0) or after (1) the target node? ";
                cin >> insertAfter;
                list.insertBeforeAfter(target, value, insertAfter);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;
            case 8:
                cout << "List of all nodes: ";
                list.displayList();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 9);

    return 0;
}