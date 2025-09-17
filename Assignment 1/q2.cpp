/*2) Design the logic to remove the duplicate elements from an Array and after the deletion the array should containtheunique elements.
*/

#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    if (n == 0) return;

    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        int k;
        for (k = 0; k < j; k++) {
            if (arr[i] == temp[k])
                break;
        }

        if (k == j) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        arr[i] =.
    n = j;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    display(arr, n);

    return 0;
}