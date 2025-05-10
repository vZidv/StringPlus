#include <check.h>
#include <stdlib.h>

#include "../src/s21_string.h"

START_TEST(test_s21_insert_normal) {
  const char *src = "Hello world!";
  const char *str = "Aboba ";
  s21_size_t start_index = 6;

  char *expected = "Hello Aboba world!";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  const char *src = "";
  const char *str = "Aboba";
  s21_size_t start_index = 0;

  char *expected = "Aboba";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_empty_str) {
  const char *src = "Hello world!";
  const char *str = "";
  s21_size_t start_index = 6;

  char *expected = "Hello world!";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_invalid_index) {
  const char *src = "Hello world!";
  const char *str = "Aboba ";
  s21_size_t start_index = 30;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_src_start) {
  const char *src = " world!";
  const char *str = "Hello";
  s21_size_t start_index = 0;

  char *expected = "Hello world!";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_src_end) {
  const char *src = "Hello ";
  const char *str = "world!";
  s21_size_t start_index = 6;

  char *expected = "Hello world!";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_other_chars) {
  const char *src = "123";
  const char *str = "@#$%";
  s21_size_t start_index = 1;

  char *expected = "1@#$%23";
  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_all_null) {
  const char *src = S21_NULL;
  const char *str = S21_NULL;
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_src_null) {
  const char *src = S21_NULL;
  const char *str = "@#$%";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_str_null) {
  const char *src = "Hello world!";
  const char *str = S21_NULL;
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_over_index) {
  const char *src = "Hello world!";
  const char *str = "Aboba ";
  s21_size_t start_index = 400;

  ck_assert_ptr_eq(s21_insert(src, str, start_index), S21_NULL);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_insert_normal);
  tcase_add_test(tc_core, test_s21_insert_empty_src);
  tcase_add_test(tc_core, test_s21_insert_empty_str);
  tcase_add_test(tc_core, test_s21_insert_invalid_index);
  tcase_add_test(tc_core, test_s21_insert_src_start);
  tcase_add_test(tc_core, test_s21_insert_src_end);
  tcase_add_test(tc_core, test_s21_insert_all_null);
  tcase_add_test(tc_core, test_s21_insert_other_chars);
  tcase_add_test(tc_core, test_s21_insert_over_index);
  tcase_add_test(tc_core, test_s21_insert_str_null);
  tcase_add_test(tc_core, test_s21_insert_src_null);

  suite_add_tcase(s, tc_core);

  return s;
}