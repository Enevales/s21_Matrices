#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EPS 1e-7

enum state { NO_ERRORS, INCORRECT_MATRIX, CALCULATION_ERROR };

enum bool_ { FALSE, TRUE };

typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;

/* ------ can be found in lib/s21_core.c ------ */

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
void fill_matrix(double value, matrix_t *A);
int valid_matrix(matrix_t *A);
double rand_double(void);
void submatrix(int row, int column, matrix_t *A, matrix_t *res);

/* ------                                ------ */

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_H