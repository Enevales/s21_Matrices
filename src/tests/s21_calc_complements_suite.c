#include "s21_tests.h"

START_TEST(calc_complements_0) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 0);
  ck_assert_double_eq(res.matrix[0][2], -20);
  ck_assert_double_eq(res.matrix[1][1], -14);
  ck_assert_double_eq(res.matrix[2][0], -8);
  ck_assert_double_eq(res.matrix[2][2], 4);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = -6;
  m.matrix[0][1] = 7;
  m.matrix[1][0] = 21;
  m.matrix[1][1] = 3;

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 3);
  ck_assert_double_eq(res.matrix[0][1], -21);
  ck_assert_double_eq(res.matrix[1][0], -7);
  ck_assert_double_eq(res.matrix[1][1], -6);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = -666;
  m.matrix[0][1] = -73;
  m.matrix[1][0] = -21000;
  m.matrix[1][1] = -36;

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], -36);
  ck_assert_double_eq(res.matrix[0][1], 21000);
  ck_assert_double_eq(res.matrix[1][0], 73);
  ck_assert_double_eq(res.matrix[1][1], -666);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);

  fill_matrix(2, &m);
  m.matrix[2][2] = 6;
  m.matrix[2][0] = 1;

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(res.matrix[0][0], 96);
  ck_assert_double_eq(res.matrix[1][2], 216);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 6, &m);

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t m = {0};
  matrix_t res = {0};

  int error = s21_calc_complements(&m, &res);
  ck_assert_int_eq(error, 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_calc_complements(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_calc_complements");
  tc12 = tcase_create("case_calc_complements");

  tcase_add_test(tc12, calc_complements_0);
  tcase_add_test(tc12, calc_complements_1);
  tcase_add_test(tc12, calc_complements_2);
  tcase_add_test(tc12, calc_complements_3);
  tcase_add_test(tc12, calc_complements_4);
  tcase_add_test(tc12, calc_complements_5);

  suite_add_tcase(s12, tc12);
  return s12;
}
