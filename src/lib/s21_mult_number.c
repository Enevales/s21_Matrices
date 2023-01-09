#include "../s21_matrix.h"

/**
 * @brief Scalar multiplication.
 * Each element is multiplied by a scalar value.

 * @param number - double value we multiply with matrix.
 * @return 1 - matrix A is invalid or allocation is failed;
 *         0 - function runs without any errors.
*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  int error = s21_create_matrix(A->rows, A->columns, result);
  if (!error) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}