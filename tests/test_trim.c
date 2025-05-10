#include <check.h>
#include <stdlib.h>

#include "../src/s21_string.h"

START_TEST(test_s21_trim_normal) {
  const char *src = "  Hello, world!  ";
  const char *trim_chars = " ";

  char *expected = "Hello, world!";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(expected, result);
  free(result);
}

START_TEST(test_s21_trim_empty_src) {
  const char *src = "";
  const char *trim_chars = " ";

  char *expected = "";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(expected, result);
  free(result);
}

START_TEST(test_s21_trim_no_trim_needed) {
  const char *src = "Hello, world!";
  const char *trim_chars = " ";

  char *expected = "Hello, world!";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(expected, result);
  free(result);
}

START_TEST(test_s21_trim_all_trimmed) {
  const char *src = "!!!";
  const char *trim_chars = "!";

  char *expected = "";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(expected, result);
  free(result);
}

START_TEST(test_s21_trim_special_chars) {
  const char *src = "\t\nText\t\n";
  const char *trim_chars = "\t\n";

  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Text");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_inner_chars) {
  const char *src = "Hello   world";
  const char *trim_chars = " ";

  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Hello   world");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_null_src) {
  char *result = s21_trim(NULL, "123");

  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_trim_mixed_chars) {
  const char *src = "**Hello!**";
  const char *trim_chars = "*!";

  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_trim_normal);
  tcase_add_test(tc_core, test_s21_trim_empty_src);
  tcase_add_test(tc_core, test_s21_trim_no_trim_needed);
  tcase_add_test(tc_core, test_s21_trim_all_trimmed);
  tcase_add_test(tc_core, test_s21_trim_special_chars);
  tcase_add_test(tc_core, test_s21_trim_inner_chars);
  tcase_add_test(tc_core, test_s21_trim_null_src);
  tcase_add_test(tc_core, test_s21_trim_mixed_chars);

  suite_add_tcase(s, tc_core);

  return s;
}