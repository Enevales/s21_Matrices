#include "../s21_matrix.h"

/**
 * @brief allocates memory for matrix
 * with given number of rows & columns

 *
 * @param value starting value
 * @return 0 if allocation was successfull
 * and it returns 1 if we're trying to
 * create zero-order matrix or allocation
 * is failed.
*/

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = (rows < 1) || (columns < 1);
  if (!error) {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      fprintf(stderr, "%s", "The allocation failed\n");
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    }
    result->rows = rows;
    result->columns = columns;
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL) {
  } else {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

/**
 * @brief filling matrix with gradually
 * incremented numbers, so that every
 * element is greater than one before.

 *
 * @param value starting value
*/
void fill_matrix(double value, matrix_t *A) {
  int rows = A->rows;
  int cols = A->columns;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A->matrix[i][j] = value;
      value++;
    }
  }
}

/**
 * @brief if allocation of memory for
 * matrix is failed or number of rows and
 * columns are less than 1, we consider
 * this matrix as incorrect;

*/
int valid_matrix(matrix_t *A) {
  int is_valid = TRUE;
  if (A == NULL) is_valid = FALSE;
  if (A->columns < 1 || A->rows < 1) is_valid = FALSE;
  return is_valid;
}

/**
 * @brief generate random number from within
 * a range of min.double and max.double (not really tho)

*/
double rand_double(void) {
  double random = ((double)rand()) / RAND_MAX;
  return DBL_MIN + random * (DBL_MAX - DBL_MIN);
}

/**
 * @brief creates n-1 order mattrix in
 * which it stores matrix created by
 * deleting given row and column.

 *
 * @param row - certain row from a larger matrix
 * that is not going to end in the resulting matrix.
 * @param column - certain column from a larger matrix
 * that is not going to end in the resulting matrix.
*/
void submatrix(int row, int column, matrix_t *A, matrix_t *res) {
  int m = 0;
  int n = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      res->matrix[m][n] = A->matrix[i][j];
      n++;
      if (n == res->columns) n = 0;
    }
    m++;
  }
}
