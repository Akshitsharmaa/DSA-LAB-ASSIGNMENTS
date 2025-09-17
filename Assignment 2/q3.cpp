 #include <iostream>
 using namespace std;
 int findMissingNumber(int arr[], int size) {
 int left = 0;
 int right = size- 1;
 while (left <= right) {
 int mid = left + (right- left) / 2;
 if (arr[mid] == arr[0] + mid) {
 left = mid + 1;
 } else {
 right = mid- 1;
 }
 }
 return arr[0] + left;
}
 int main() {
 int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
 int size = sizeof(arr) / sizeof(arr[0]);
 int missingNumber = findMissingNumber(arr, size);
 cout << "The missing number is: " << missingNumber << endl;
 return 0;
 }
