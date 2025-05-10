#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strpbrk_normal) {
  char *str = "Hello, world!";
  char *delim = " ,!";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
  char *str = "Hello, world!";
  char *delim = "xyz";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_empty_str) {
  char *str = "";
  char *delim = "abc";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_empty_delim) {
  char *str = "abc";
  char *delim = "";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_multiple_matches) {
  char *str = "abcdef";
  char *delim = "xdcy";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_case_sensitive) {
  char *str = "Hello";
  char *delim = "LO";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), strpbrk(str, delim));
}
END_TEST

START_TEST(test_s21_strpbrk_str_NUll) {
  char *str = S21_NULL;
  char *delim = "LO";
  ck_assert_ptr_eq(s21_strpbrk(str, delim), S21_NULL);
}
END_TEST

START_TEST(test_s21_strpbrk_delim_NUll) {
  char *str = "Hello";
  char *delim = S21_NULL;
  ck_assert_ptr_eq(s21_strpbrk(str, delim), S21_NULL);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_normal);
  tcase_add_test(tc_core, test_s21_strpbrk_no_match);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_str);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_delim);
  tcase_add_test(tc_core, test_s21_strpbrk_multiple_matches);
  tcase_add_test(tc_core, test_s21_strpbrk_case_sensitive);
  tcase_add_test(tc_core, test_s21_strpbrk_str_NUll);
  tcase_add_test(tc_core, test_s21_strpbrk_delim_NUll);

  suite_add_tcase(s, tc_core);

  return s;
}