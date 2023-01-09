#include "../s21_matrix.h"

void submatrix_min(int column, matrix_t *A, matrix_t *res) {
  int m = 0;
  int n = 0;
  for (int i = 1; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      res->matrix[m][n] = A->matrix[i][j];
      n++;
      if (n == res->columns) n = 0;
    }
    m++;
  }
}

/**
 * @brief recursive function, that finds
 * a determinant of a square matrix. It refers
 * to itself, if order of a given matrix is
 * greater than 2.

 *
 * @return 1 - matrix is invalid;
 *         2 - matrix is not square (if matrix)
 * doesn't have same number of rows & columns;
 *         0 - function runs without any errors.
*/
int s21_determinant(matrix_t *A, double *result) {
  if (!valid_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }

  double det = 0;
  int order = A->rows;
  matrix_t temp = {0};
  double det_temp = 0;

  if (order == 1) {
    det = A->matrix[0][0];
  } else if (order == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (order > 2) {
    s21_create_matrix(order - 1, order - 1, &temp);
    for (int i = 0; i < order; i++) {
      submatrix_min(i, A, &temp);
      s21_determinant(&temp, &det_temp);
      if ((i % 2) != 0) det_temp *= -1;
      det += A->matrix[0][i] * det_temp;
    }
    s21_remove_matrix(&temp);
  }
  *result = det;
  return NO_ERRORS;
}