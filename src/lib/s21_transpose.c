#include "../s21_matrix.h"

/**
 * @brief switches matrix rows with its columns with
 * their numbers retained

 *
 * @return 1 - matrix is invalid or allocation is failed;
 *         0 - function runs without any errors.
*/
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  int error = s21_create_matrix(A->columns, A->rows, result);
  if (!error) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}