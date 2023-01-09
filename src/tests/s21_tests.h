#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <stdio.h>
#include <time.h>

#include "../s21_matrix.h"

Suite *suite_s21_core(void);
Suite *suite_s21_eq(void);
Suite *suite_s21_sub(void);
Suite *suite_s21_sum(void);
Suite *suite_s21_mult_num(void);
Suite *suite_s21_mult_matrix(void);
Suite *suite_s21_transpose(void);
Suite *suite_s21_calc_complements(void);
Suite *suite_s21_determinant(void);
Suite *suite_s21_inverse_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // S21_TESTS_H