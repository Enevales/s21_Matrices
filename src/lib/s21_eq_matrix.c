#include "../s21_matrix.h"

/**
 * @brief compares to matrices element
 * by element. Comparison is up to and
 * including 7 decimal places.

 *
 * @return TRUE (1) if matrices are equal.
 * FALSE (0) if matrices are not equal.
*/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!valid_matrix(A) || !valid_matrix(B)) return FALSE;
  int is_equal = TRUE;
  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) return FALSE;
      }
    }
  } else {
    is_equal = FALSE;
  }
  return is_equal;
}