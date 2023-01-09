#include "../s21_matrix.h"
#include "s21_tests.h"

START_TEST(mult_matrix_0) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &n);
  fill_matrix(0, &m);
  fill_matrix(1, &n);

  matrix_t check = {0};
  s21_create_matrix(3, 3, &check);

  int error = s21_mult_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < res.rows; i++) {
    for (int j = 0; j < res.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < n.rows; k++) {
        check.matrix[i][j] += m.matrix[i][k] * n.matrix[k][j];
      }
    }
  }

  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);
  ck_assert_double_eq(res.matrix[0][0], 18);
  ck_assert_double_eq(res.matrix[2][2], 132);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(1, 3, &m);
  s21_create_matrix(3, 1, &n);

  fill_matrix(0, &m);
  fill_matrix(1, &n);

  int error = s21_mult_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.rows, 1);
  ck_assert_int_eq(res.columns, 1);
  ck_assert_double_eq(res.matrix[0][0], 8);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(2, 2, &n);

  int error = s21_mult_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(3, 3, &n);

  int error = s21_mult_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 3, &m);
  s21_create_matrix(3, 2, &n);

  fill_matrix(1, &m);
  fill_matrix(3, &n);
  int error = s21_mult_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 34);
  ck_assert_double_eq(res.matrix[0][1], 40);
  ck_assert_double_eq(res.matrix[1][0], 79);
  ck_assert_double_eq(res.matrix[1][1], 94);

  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_mult_matrix(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_mult_matrix");
  tc12 = tcase_create("case_mult_matrix");

  tcase_add_test(tc12, mult_matrix_0);
  tcase_add_test(tc12, mult_matrix_1);
  tcase_add_test(tc12, mult_matrix_2);
  tcase_add_test(tc12, mult_matrix_3);
  tcase_add_test(tc12, mult_matrix_4);

  suite_add_tcase(s12, tc12);
  return s12;
}
