#include "s21_tests.h"

START_TEST(determinant_0) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(3, 3, &m);

  fill_matrix(1, &m);
  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(3, 3, &m);

  fill_matrix(5, &m);
  m.matrix[0][0] = 15;
  m.matrix[1][1] = 13;
  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 442);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = 4;
  m.matrix[0][1] = 8;
  m.matrix[1][0] = 12;
  m.matrix[1][1] = 13;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, -44);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = 4;
  m.matrix[0][1] = 12;
  m.matrix[1][0] = -5;
  m.matrix[1][1] = 6;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 84);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = 4;
  m.matrix[0][1] = 12;
  m.matrix[1][0] = -5;
  m.matrix[1][1] = 6;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 84);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(5, 5, &m);

  fill_matrix(2, &m);
  m.matrix[3][2] = 13;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(3, 5, &m);

  fill_matrix(2, &m);

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 2);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(-2, 0, &m);

  fill_matrix(2, &m);

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 1);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(2, 2, &m);

  m.matrix[0][0] = -4.56;
  m.matrix[0][1] = 8;
  m.matrix[1][0] = 12;
  m.matrix[1][1] = -0.9;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, -91.896);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t m = {0};
  double det = 0;
  s21_create_matrix(7, 7, &m);

  fill_matrix(2, &m);
  m.matrix[1][3] = 1;
  m.matrix[3][3] = 5;
  m.matrix[6][3] = 9;

  int error = s21_determinant(&m, &det);
  ck_assert_int_eq(error, 0);

  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_s21_determinant(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_determinant");
  tc12 = tcase_create("case_determinant");

  tcase_add_test(tc12, determinant_0);
  tcase_add_test(tc12, determinant_1);
  tcase_add_test(tc12, determinant_2);
  tcase_add_test(tc12, determinant_3);
  tcase_add_test(tc12, determinant_4);
  tcase_add_test(tc12, determinant_5);
  tcase_add_test(tc12, determinant_6);
  tcase_add_test(tc12, determinant_7);
  tcase_add_test(tc12, determinant_8);
  tcase_add_test(tc12, determinant_9);

  suite_add_tcase(s12, tc12);
  return s12;
}
