#include "s21_tests.h"

START_TEST(matrix_eq_0) {
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &n);
  int is_equal = s21_eq_matrix(&m, &n);
  ck_assert_int_eq(is_equal, 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(matrix_eq_1) {
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(-1, -1, &m);
  s21_create_matrix(0, 0, &n);
  int is_equal = s21_eq_matrix(&m, &n);
  ck_assert_int_eq(is_equal, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(matrix_eq_2) {
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(3, 4, &m);
  s21_create_matrix(3, 4, &n);
  fill_matrix(5, &m);
  fill_matrix(5, &n);
  int is_equal = s21_eq_matrix(&m, &n);
  ck_assert_int_eq(is_equal, 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(matrix_eq_3) {
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(3, 4, &m);
  s21_create_matrix(3, 3, &n);
  fill_matrix(5, &m);
  fill_matrix(5, &n);
  int is_equal = s21_eq_matrix(&m, &n);
  ck_assert_int_eq(is_equal, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(matrix_eq_4) {
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(2, 2, &n);
  fill_matrix(6, &m);
  fill_matrix(5, &n);
  int is_equal = s21_eq_matrix(&m, &n);
  ck_assert_int_eq(is_equal, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

Suite *suite_s21_eq(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_eq");
  tc12 = tcase_create("case_eq");

  tcase_add_test(tc12, matrix_eq_0);
  tcase_add_test(tc12, matrix_eq_1);
  tcase_add_test(tc12, matrix_eq_2);
  tcase_add_test(tc12, matrix_eq_3);
  tcase_add_test(tc12, matrix_eq_4);

  suite_add_tcase(s12, tc12);
  return s12;
}
