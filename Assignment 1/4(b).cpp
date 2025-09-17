// 4) Implement the logic to find the matrix multiplication

#include <iostream>
using namespace std;

void multiplyMatrices(int mat1[][3], int mat2[][2], int result[][2], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r1 = 2, c1 = 3, r2 = 3, c2 = 2;

    int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int mat2[3][2] = { {7, 8}, {9, 10}, {11, 12} };
    int result[2][2]; 

    if (c1 != r2) {
        cout << "Matrix multiplication not possible with the given matrices." << endl;
        return 0;
    }

    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

    cout << "Resultant Matrix after multiplication:" << endl;
    displayMatrix(result, r1, c2);

    return 0;
}