//Write a program to find sum of every row and every column in a two-dimensional array.

#include <iostream>
using namespace std;

void calculateRowSums(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}

void calculateColumnSums(int matrix[][3], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int rows = 3, cols = 3;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    calculateRowSums(matrix, rows, cols);

    calculateColumnSums(matrix, rows, cols);

    return 0;
}
