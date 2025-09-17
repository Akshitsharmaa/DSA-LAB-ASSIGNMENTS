// Implement the logic to Find the transpose of a matrix

#include <iostream>
using namespace std;

void transposeMatrix(int matrix[][3], int transpose[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 3, cols = 3;

    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int transpose[3][3];

    transposeMatrix(matrix, transpose, rows, cols);

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix, rows, cols);

    cout << "Transpose Matrix:" << endl;
    displayMatrix(transpose, rows, cols);

    return 0;
}
