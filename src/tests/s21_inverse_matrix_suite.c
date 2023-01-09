#include "s21_tests.h"

START_TEST(inverse_matrix_0) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  int error = s21_inverse_matrix(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 1);
  ck_assert_double_eq(res.matrix[0][1], -1);
  ck_assert_double_eq(res.matrix[1][1], 41);
  ck_assert_double_eq(res.matrix[2][0], 27);
  ck_assert_double_eq(res.matrix[2][2], 24);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 3, &m);

  int error = s21_inverse_matrix(&m, &res);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  fill_matrix(1, &m);

  int error = s21_inverse_matrix(&m, &res);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t m = {0};
  matrix_t res = {0};

  int error = s21_inverse_matrix(&m, &res);
  ck_assert_int_eq(error, 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 4;

  int error = s21_inverse_matrix(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq_tol(res.matrix[0][0], 0.8, EPS);
  ck_assert_double_eq_tol(res.matrix[0][1], -0.6, EPS);
  ck_assert_double_eq_tol(res.matrix[1][0], -0.2, EPS);
  ck_assert_double_eq_tol(res.matrix[1][1], 0.4, EPS);

  matrix_t check = {0};
  s21_mult_matrix(&res, &m, &check);

  ck_assert_double_eq_tol(check.matrix[0][0], 1, EPS);
  ck_assert_double_eq_tol(check.matrix[0][1], 0, EPS);
  ck_assert_double_eq_tol(check.matrix[1][0], 0, EPS);
  ck_assert_double_eq_tol(check.matrix[1][1], 1, EPS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_inverse_matrix(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_inverse_matrix");
  tc12 = tcase_create("case_inverse_matrix");

  tcase_add_test(tc12, inverse_matrix_0);
  tcase_add_test(tc12, inverse_matrix_1);
  tcase_add_test(tc12, inverse_matrix_2);
  tcase_add_test(tc12, inverse_matrix_3);
  tcase_add_test(tc12, inverse_matrix_4);

  suite_add_tcase(s12, tc12);
  return s12;
}