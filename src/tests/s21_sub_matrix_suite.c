#include "s21_tests.h"

START_TEST(sub_matrix_0) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &n);

  fill_matrix(4, &m);
  fill_matrix(3, &n);
  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  matrix_t check = {0};
  s21_create_matrix(3, 3, &check);

  int a = 4;
  int b = 3;
  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      check.matrix[i][j] = a - b;
      a++;
      b++;
    }
  }
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);
  ck_assert_double_eq(res.matrix[0][2], 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &n);

  fill_matrix(-2, &m);
  fill_matrix(3, &n);
  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  matrix_t check = {0};
  s21_create_matrix(3, 3, &check);

  int a = -2;
  int b = 3;
  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      check.matrix[i][j] = a - b;
      a++;
      b++;
    }
  }

  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);
  ck_assert_double_eq(res.matrix[0][2], -5);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(2, 2, &n);
  fill_matrix(5, &m);
  fill_matrix(3, &n);

  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 3, &m);
  s21_create_matrix(3, 4, &n);
  fill_matrix(5, &m);
  fill_matrix(3, &n);

  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(2, 2, &n);
  fill_matrix(5, &m);
  fill_matrix(3, &n);

  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 5, &m);
  s21_create_matrix(3, 5, &n);
  fill_matrix(5, &m);
  fill_matrix(3, &n);

  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_6) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(2, 2, &n);

  fill_matrix(0, &m);
  fill_matrix(0, &n);
  fill_matrix(3, &n);

  int error = s21_sub_matrix(&m, &n, &res);
  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix_7) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t check = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(2, 2, &n);
  s21_create_matrix(2, 2, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < n.columns; j++) {
      double a = rand_double();
      double b = rand_double();
      m.matrix[i][j] = a;
      n.matrix[i][j] = b;
      check.matrix[i][j] = a - b;
    }
  }
  matrix_t res = {0};

  int error = s21_sub_matrix(&m, &n, &res);
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 1);

  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sub_matrix_8) {
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t check = {0};
  s21_create_matrix(2, 2, &m);
  s21_create_matrix(2, 2, &n);
  s21_create_matrix(2, 2, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < n.columns; j++) {
      double a = rand_double();
      double b = rand_double();
      m.matrix[i][j] = a;
      n.matrix[i][j] = b;
      check.matrix[i][j] = b - a;
    }
  }
  matrix_t res = {0};

  int error = s21_sub_matrix(&m, &n, &res);
  int is_equal = s21_eq_matrix(&res, &check);
  ck_assert_int_eq(is_equal, 0);

  ck_assert_int_eq(error, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_sub");
  tc12 = tcase_create("case_sub");

  tcase_add_test(tc12, sub_matrix_0);
  tcase_add_test(tc12, sub_matrix_1);
  tcase_add_test(tc12, sub_matrix_2);
  tcase_add_test(tc12, sub_matrix_3);
  tcase_add_test(tc12, sub_matrix_4);
  tcase_add_test(tc12, sub_matrix_5);
  tcase_add_test(tc12, sub_matrix_6);
  tcase_add_test(tc12, sub_matrix_7);
  tcase_add_test(tc12, sub_matrix_8);

  suite_add_tcase(s12, tc12);
  return s12;
}
