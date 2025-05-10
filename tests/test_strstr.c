#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strstr_normal) {
  char *haystack = "Hello, world!";
  char *needle = "world";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_longHaystack) {
  char *haystack =
      "This is a test string exactly 100 characters long, "
      "including spaces and punctuation";
  char *needle = "and";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_unicode) {
  char *haystack =
      "Котлета — это круглый биточек из мясного фарша, обжаренный "
      "на сковороде или запечённый в духовке.";
  char *needle = "сковороде";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_embeddedNull) {
  char haystack[] = {'H', 'e', 'l', 'l', 'o', '\0',
                     'w', 'o', 'r', 'l', 'd', '\0'};
  char *needle = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_haystackNull) {
  char *haystack = S21_NULL;
  char *needle = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), S21_NULL);
}
END_TEST

START_TEST(test_s21_strstr_needleNull) {
  char *haystack = "Hello, world!";
  char *needle = S21_NULL;
  ck_assert_ptr_eq(s21_strstr(haystack, needle), S21_NULL);
}
END_TEST

START_TEST(test_s21_strstr_allNull) {
  char *haystack = S21_NULL;
  char *needle = S21_NULL;
  ck_assert_ptr_eq(s21_strstr(haystack, needle), S21_NULL);
}
END_TEST

START_TEST(test_s21_strstr_allEFO) {
  char *haystack = "\0";
  char *needle = "\0";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_needleEFO) {
  char *haystack = "Hello, world!";
  char *needle = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_needle_longer_than_haystack) {
  char *haystack = "Hi";
  char *needle = "Hello, world!";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_no_match) {
  char *haystack = "Hello, world!";
  char *needle = "planet";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s = suite_create("s21_strtr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_normal);
  tcase_add_test(tc_core, test_s21_strstr_longHaystack);
  tcase_add_test(tc_core, test_s21_strstr_unicode);
  tcase_add_test(tc_core, test_s21_strstr_embeddedNull);
  tcase_add_test(tc_core, test_s21_strstr_haystackNull);
  tcase_add_test(tc_core, test_s21_strstr_needleNull);
  tcase_add_test(tc_core, test_s21_strstr_allNull);
  tcase_add_test(tc_core, test_s21_strstr_allEFO);
  tcase_add_test(tc_core, test_s21_strstr_needleEFO);
  tcase_add_test(tc_core, test_s21_strstr_needle_longer_than_haystack);
  tcase_add_test(tc_core, test_s21_strstr_no_match);

  suite_add_tcase(s, tc_core);
  return s;
}