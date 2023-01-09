#include "../s21_matrix.h"

/**
 * @brief Multiplication of two matrices.
 * Multiplying each element of the column of the
 * first matrix with each element of rows of the
 * second matrix and add them all.

 *
 * @return 1 - matrix A or matrix B is invalid;
 *         2 - num. of columns of first matrix doesn't correspond
 * to num. of rows of second matrix.
 *         0 - function runs without any errors.
*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!valid_matrix(A) || !valid_matrix(B)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int error = s21_create_matrix(A->rows, B->columns, result);
  if (!error) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error;
}