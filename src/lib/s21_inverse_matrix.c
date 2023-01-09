#include "../s21_matrix.h"

/**
 * @brief finds inverse of a square matrix
 * by constructing matrix of algebraic
 * complements, then transposing it and multiplying
 * each element of a matrix by 1/det(A).

 *
 * @return 1 - matrix is invalid;
 *         2 - matrix is not square (if matrix)
 * doesn't have same number of rows & columns or determinant of a matrix is
 ZERO;
 *         0 - function runs without any errors.
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }
  double det = 0;
  int error = s21_determinant(A, &det);
  if (det == 0 || error) return CALCULATION_ERROR;
  if (!error) {
    matrix_t temp_0 = {0};
    matrix_t temp_1 = {0};
    s21_calc_complements(A, &temp_0);
    s21_transpose(&temp_0, &temp_1);
    s21_mult_number(&temp_1, 1 / det, result);

    s21_remove_matrix(&temp_0);
    s21_remove_matrix(&temp_1);
  }
  return error;
}