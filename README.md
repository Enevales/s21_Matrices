# Matrices
---
An educational project that requires the development of a library that allows you to work with matrices ([about matrix structure](#Overview)) and perform [various operations](#Matrix/operations).


### Contents:

* [Overview](#Overview)
* [How to build](#How/to/build) 
* [Matrix operations](#Matrix/operations).
* [Technological description](#Technological/description)
* [Demonstration](#Demo)

### Overview:
---
Matrix structure in C language:

```c
typedef struct matrix_struct {
 double** matrix;
 int rows;
 int columns;
} matrix_t;
```

### How to build: 
---
> $ cd src
> $ make

### Matrix operations:

| Functions  | Description   |
|---|---|
| int s21_create_matrix(int rows, int columns, matrix_t *result); | Creating matrices   |
| void s21_remove_matrix(matrix_t *A);  |  Cleaning of matrices  |
| int s21_eq_matrix(matrix_t *A, matrix_t *B); | Matrix comparison  |
| int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  | Adding matrices |
| int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result); | Substracting matrices |
| int s21_mult_number(matrix_t *A, double number, matrix_t *result); |  Matrix multiplication by scalar |
| int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  | Multiplication of two matrices  |
| int s21_transpose(matrix_t *A, matrix_t *result);  |  Matrix transpose |
| int s21_calc_complements(matrix_t *A, matrix_t *result); |  Minor of matrix and matrix of algebraic complements  |
| int s21_determinant(matrix_t *A, double *result); | Matrix determinant |
| int s21_inverse_matrix(matrix_t *A, matrix_t *result);  | Inverse of the matrix |

### Technological description:
---
- The library was implemented in C language of C11 standard using gcc compiler. Based on the POSIX.1-2017 standard. The library developed according to the principles of structured programming
- Full coverage of the library functions code with unit-tests with the Check library.
- Supported systems: Linux-based systems and macOS
