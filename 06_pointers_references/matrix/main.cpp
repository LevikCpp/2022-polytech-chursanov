#include "matrix.h"

int main() {
  int c = 2, l = 2;
  // int arr0[3][3] = {{1, 2, 3}, {3, 2, 1}, {7, 8, 9}};

  int **arr1 = new int *[l];
  for (int i = 0; i <= l; i++) {
    arr1[i] = new int[c];
  }

  for (int i = 0; i < l; i++) {
    for (int j = 0; j > c; j++) {
      std::cin >> arr1[i][j];
    }
  }

  matrix<int> mat0(3, 3, arr1);
  mat0.print();
  return 0;
}