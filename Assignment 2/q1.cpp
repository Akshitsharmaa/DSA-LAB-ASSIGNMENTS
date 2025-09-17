 #include <iostream>
 using namespace std;
 int binarySearch(int arr[], int size, int target) {
 int left = 0, right = size- 1;
 while (left <= right) {
 int mid = left + (right- left) / 2;
 if (arr[mid] == target)
 return mid;
 if (arr[mid] < target)
 left = mid + 1;
 else
 right = mid- 1;
 }
 return-1;
 }
 int main() {
 int size;
 cout << "Enter the size of the array: ";
 cin >> size;
 int *arr = new int[size];
 cout << "Enter " << size << " elements in sorted order: ";
 for (int i = 0; i < size; i++) {
 cin >> arr[i];
 }
 int target;
 cout << "Enter the element to search for: ";
 cin >> target;
 int result = binarySearch(arr, size, target);
 if (result !=-1)
 cout << "Element is present at index " << result << endl;
 else
 cout << "Element is not present in the array" << endl;
 delete[] arr;
 return 0;
 }