#include <iostream>
#include <vector>
using namespace std;

// Improved Selection Sort Function
void improvedSelectionSort(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left < right) {
        int minIdx = left, maxIdx = left;

        // Find the minimum and maximum elements in the current range
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }

        // Place the minimum at the beginning
        swap(arr[left], arr[minIdx]);

        // Adjust maxIdx if it was swapped with left
        if (maxIdx == left) {
            maxIdx = minIdx;
        }

        // Place the maximum at the end
        swap(arr[right], arr[maxIdx]);

        // Narrow the range
        left++;
        right--;
    }
}

// Function to display the array
void display(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main program
int main() {
    vector<int> arr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr);

    improvedSelectionSort(arr);

    cout << "Array after Improved Selection Sort: ";
    display(arr);

    return 0;
}