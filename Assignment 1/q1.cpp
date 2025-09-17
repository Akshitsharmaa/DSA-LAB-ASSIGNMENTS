/*1) Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT

*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void create(int arr[], int &n) {
    cout << "Enter the number of elements: ";
    cin >> n;
    if(n > MAX_SIZE) {
        cout << "Array size exceeds maximum limit.\n";
        return;
    }
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display(int arr[], int n) {
    if(n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements are:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int &n, int position, int value) {
    if(n >= MAX_SIZE) {
        cout << "Array is full. Cannot insert new element.\n";
        return;
    }
    if(position < 0 || position > n) {
        cout << "Invalid position!\n";
        return;
    }
    for(int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;
    cout << "Element inserted.\n";
}

void deleteElement(int arr[], int &n, int position) {
    if(n == 0) {
        cout << "Array is empty. Cannot delete element.\n";
        return;
    }
    if(position < 0 || position >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for(int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch(int arr[], int n, int value) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == value) {
            cout << "Element found at position " << i << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice, position, value;

    do {
        cout << "\n----MENU----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                create(arr, n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                cout << "Enter the position to insert (0-based index): ";
                cin >> position;
                cout << "Enter the value to insert: ";
                cin >> value;
                insert(arr, n, position, value);
                break;
            case 4:
                cout << "Enter the position to delete (0-based index): ";
                cin >> position;
                deleteElement(arr, n, position);
                break;
            case 5:
                cout << "Enter the value to search: ";
                cin >> value;
                linearSearch(arr, n, value);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}