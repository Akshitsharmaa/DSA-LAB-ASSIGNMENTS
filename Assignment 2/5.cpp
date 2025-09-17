 #include <iostream>
 using namespace std;
 // Function to deallocate memory for a matrix
 void Entry(int*& arr, int n)
 {
 cout << "Enter the elements in the matrix \n";
 for (int i = 0; i < n; i++)
 {
 }
 }
 cin >> arr[i];
 // diagonal matrix
 void diagonalmatrix()
 {
 int n;
 cout << "Enter the size of the matrix: ";
 cin >> n;
 int *arr = new int[n];
Entry(arr, n);
 cout << "The diagonal matrix is : \n";
 for (int i = 0; i < n; i++)
 {
 }
 for (int j = 0; j < n; j++)
 {
 if (i == j)
 {
 cout << arr[i] << " ";
 }
 else
 {
 cout << "0 ";
 }
 }
 cout << "\n";
 delete[] arr;
}
 // tridiagonal matrix
 void tri_diagonal()
 {
 int n;
 cout << "Enter the size of the matrix: ";
 cin >> n;
 int size = n + 2 * (n- 1);
 int *arr = new int[size];
 Entry(arr, size);
 cout << "The tri-diagonal matrix is : \n";
 int k = 0;
 for (int i = 0; i < n; i++)
 {
 for (int j = 0; j < n; j++)
 {
 if ((i- j) == 1 || j == i || (i- j) ==-1)
{
 cout << arr[k] << " ";
 k++;
 }
 else
 {
 cout << "0 ";
 }
 }
 cout << "\n";
 }
 delete[] arr;
 }
 // lower diagonal matrix
 void lower_diagonal()
 {
 int n;
 cout << "Enter the size of the matrix: ";
 cin >> n;
int size = (n * (n + 1)) / 2;
 int *arr = new int[size];
 Entry(arr, size);
 cout << "The lower triangular matrix is : \n";
 int k = 0;
 for (int i = 0; i < n; i++)
 {
 }
 for (int j = 0; j < n; j++)
 {
 if (i >= j)
 {
 cout << arr[k] << " ";
 k++;
 }
 else
 {
 cout << "0 ";
 }
 }
 cout << "\n";
 delete[] arr;
 }
 // upperdiagonal matrix
 void upper_diagonal()
{
 int n;
 cout << "Enter the size of the matrix: ";
 cin >> n;
 int size = (n * (n + 1)) / 2;
 int *arr = new int[size];
 Entry(arr, size);
 cout << "The upper triangular matrix is : \n";
 int k = 0;
 for (int i = 0; i < n; i++)
 {
 for (int j = 0; j < n; j++)
 {
 if (i <= j)
 {
 cout << arr[k] << " ";
 k++;
 }
 else
 {
cout << "0 ";
 }
 }
 cout << "\n";
 }
 delete[] arr;
 }
 // symmetric matrix
 void symmetric_matrix()
 {
 int n;
 cout << "Enter the size of the matrix: ";
 cin >> n;
 int size = (n * (n + 1)) / 2;
 int *arr = new int[size];
 Entry(arr, size);
 cout << "The symmetric matrix is : \n";
 int x=0;
 for (int i = 0; i < n; ++i)
{
 int step{};
 int y = i;
 for (int j=0; j < n; ++j)
 {
 if (i <= j)
 {
 cout << arr[x] << ' ';
 ++x;
 }
 if (i > j)
 {
 cout << arr[y] << ' ';
 y += n-step- 1;
 ++step;
 }
 }
 cout << '\n';
 }
 delete[] arr;
 }
 int main()
 {
 diagonalmatrix();
 tri_diagonal();
 upper_diagonal();
 lower_diagonal();
 symmetric_matrix();
 return 0;
}