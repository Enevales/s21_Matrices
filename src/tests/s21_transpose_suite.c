#include "s21_tests.h"

START_TEST(transpose_0) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);
  m.matrix[0][0] = 17;
  m.matrix[0][1] = 86;
  m.matrix[1][0] = 53;
  m.matrix[1][1] = 20;

  int error = s21_transpose(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 17);
  ck_assert_double_eq(res.matrix[0][1], 53);
  ck_assert_double_eq(res.matrix[1][0], 86);
  ck_assert_double_eq(res.matrix[1][1], 20);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t m = {0};
  matrix_t res = {0};
  int error = s21_transpose(&m, &res);
  ck_assert_int_eq(error, 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_transpose(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_transpose");
  tc12 = tcase_create("case_transpose");

  tcase_add_test(tc12, transpose_0);
  tcase_add_test(tc12, transpose_1);

  suite_add_tcase(s12, tc12);
  return s12;
}
