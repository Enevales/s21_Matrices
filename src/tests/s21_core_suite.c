#include "s21_tests.h"

START_TEST(matrix_core_0) {
  matrix_t m = {0};
  int result = s21_create_matrix(0, 0, &m);
  int is_valid = valid_matrix(&m);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(is_valid, 0);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(matrix_core_1) {
  matrix_t m = {0};
  int result = s21_create_matrix(2, 2, &m);
  int is_valid = valid_matrix(&m);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(is_valid, 1);
  ck_assert_int_eq(m.rows, 2);
  ck_assert_int_eq(m.columns, 2);
  fill_matrix(9, &m);
  ck_assert_double_eq(10, m.matrix[0][1]);
  ck_assert_double_eq(11, m.matrix[1][0]);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(matrix_core_2) {
  matrix_t m = {0};
  int result = s21_create_matrix(12, 12, &m);
  int is_valid = valid_matrix(&m);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(is_valid, 1);
  ck_assert_int_eq(m.rows, 12);
  ck_assert_int_eq(m.columns, 12);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_s21_core(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_core");
  tc12 = tcase_create("case_core");

  tcase_add_test(tc12, matrix_core_0);
  tcase_add_test(tc12, matrix_core_1);
  tcase_add_test(tc12, matrix_core_2);

  suite_add_tcase(s12, tc12);
  return s12;
}
