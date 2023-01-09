#include "../s21_matrix.h"

/**
 * @brief find the matrix of algebraic complements
 * of a given SQUARE matrix by finding minor of each element,
 * (determinant of a submatrix obtained by deleting out the
 * i-th row and the j-th column) and multiplying each
 * minor by -1^(i+j)

 *
 * @return 1 - matrix is invalid or allocation is failed;
 *         2 - given matrix isn't square.
 *         0 - function runs without any errors.
*/
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }
  int error = s21_create_matrix(A->rows, A->columns, result);
  if (!error) {
    matrix_t temp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        submatrix(i, j, A, &temp);
        if (s21_determinant(&temp, &result->matrix[i][j])) break;
        if ((i + j + 2) % 2 != 0) result->matrix[i][j] *= -1;
      }
    }
    s21_remove_matrix(&temp);
  }
  return error;
}