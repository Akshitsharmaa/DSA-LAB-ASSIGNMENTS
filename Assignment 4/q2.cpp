#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int& size) {
    if (size == 0 || size == 1) {
        return;  // No duplicates if array has 0 or 1 element
    }

    int newSize = 1;  // Start with the first element as unique

    // Traverse through the array
    for (int i = 1; i < size; i++) {
        bool isDuplicate = false;
        // Compare the current element with all previous elements
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;  // Element already exists, so skip it
                break;
            }
        }

        // If no duplicate is found, add it to the "unique" section
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    // Update the size of the array to reflect the number of unique elements
    size = newSize;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 20, 30, 40, 10, 50, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
	    displayArray(arr, size);

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    displayArray(arr, size);

    return 0;
}