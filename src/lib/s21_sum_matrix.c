#include "../s21_matrix.h"

/**
 * @brief The sum of two matrices.

 * @return 1 - matrix A  or B is invalid;
           2 - number of rows or/and columns of first
 * matrix isn't equal to number of rows & columns of second
 * matrix.
 *         0 - function runs without any errors.
*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    return CALCULATION_ERROR;
  int error = s21_create_matrix(A->rows, B->columns, result);
  if (!error) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return error;
}
