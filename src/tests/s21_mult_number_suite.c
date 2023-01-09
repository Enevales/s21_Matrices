#include "s21_tests.h"

START_TEST(mult_num_0) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  fill_matrix(0, &m);
  matrix_t check = {0};
  s21_create_matrix(3, 3, &check);

  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      check.matrix[i][j] = m.matrix[i][j] * 5;
    }
  }
  int error = s21_mult_number(&m, 5, &res);
  ck_assert_int_eq(error, 0);
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);
  ck_assert_double_eq(res.matrix[0][0], 0);
  ck_assert_double_eq(res.matrix[0][2], 10);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_num_1) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  fill_matrix(0, &m);
  fill_matrix(1, &res);

  int error = s21_mult_number(&m, 6.66, &res);
  ck_assert_int_eq(error, 0);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_num_2) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  fill_matrix(0, &m);

  int error = s21_mult_number(&m, 6.66, &res);
  ck_assert_int_eq(error, 0);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_num_3) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  fill_matrix(0, &m);
  fill_matrix(1, &res);

  matrix_t check = {0};
  s21_create_matrix(3, 3, &check);

  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      check.matrix[i][j] = m.matrix[i][j] * 5;
    }
  }
  int error = s21_mult_number(&m, 5, &res);
  ck_assert_int_eq(error, 0);
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);
  ck_assert_double_eq(res.matrix[0][0], 0);
  ck_assert_double_eq(res.matrix[0][1], 5);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_num_4) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);

  matrix_t check = {0};
  s21_create_matrix(2, 2, &check);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = rand_double();
      check.matrix[i][j] = m.matrix[i][j] * 4.2;
    }
  }

  int error = s21_mult_number(&m, 4.2, &res);
  ck_assert_int_eq(error, 0);
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_mult_num(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_mult_num");
  tc12 = tcase_create("case_mult_num");

  tcase_add_test(tc12, mult_num_0);
  tcase_add_test(tc12, mult_num_1);
  tcase_add_test(tc12, mult_num_2);
  tcase_add_test(tc12, mult_num_3);
  tcase_add_test(tc12, mult_num_4);

  suite_add_tcase(s12, tc12);
  return s12;
}
