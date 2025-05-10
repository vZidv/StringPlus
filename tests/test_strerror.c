#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strerror_normal) {
  int errnum = 2;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_s21_strerror_boundary_min) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_s21_strerror_random_valid) {
  int errnum = 42;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_s21_strerror_all_codes) {
  for (int errnum = 0; errnum <= 132; errnum++) {
    ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
  }
}
END_TEST

START_TEST(test_s21_strerror_large_number) {
  int errnum = 500;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_s21_strerror_small_number) {
  int errnum = -1;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strerror_normal);
  tcase_add_test(tc_core, test_s21_strerror_boundary_min);
  tcase_add_test(tc_core, test_s21_strerror_random_valid);
  tcase_add_test(tc_core, test_s21_strerror_all_codes);
  tcase_add_test(tc_core, test_s21_strerror_large_number);
  tcase_add_test(tc_core, test_s21_strerror_small_number);

  suite_add_tcase(s, tc_core);
  return s;
}