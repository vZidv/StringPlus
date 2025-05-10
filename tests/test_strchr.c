#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_strchr_normal) {
  char *str = "Hello, world!";
  int findChar = 'w';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_longStr) {
  char *str =
      "This is a test string exactly 100 characters long, including "
      "spaces and punctuation, world!";
  int findChar = 'w';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_strNull) {
  char *str = S21_NULL;
  int findChar = 'w';
  ck_assert_ptr_eq(s21_strchr(str, findChar), S21_NULL);
}
END_TEST

START_TEST(test_s21_strchr_findCharEOF) {
  char *str = "Hello, world!";
  int findChar = '\0';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_strEOF) {
  char *str = "\0";
  int findChar = 'w';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_allEOF) {
  char *str = "\0";
  int findChar = '\0';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_embeddedNull) {
  char str[] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                'W', 'o', 'r', 'l', 'd', '!'};
  int findChar = 'W';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  char *str = "Hello, world!";
  int findChar = 'z';
  ck_assert_ptr_eq(s21_strchr(str, findChar), strchr(str, findChar));
}
END_TEST

START_TEST(test_s21_strchr_negative_char) {
  char *str = "Hello";
  int c = -42;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_last_char) {
  char *str = "Hello!";
  int c = '!';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_multiple_occurrences) {
  char *str = "test_test_test";
  int c = 't';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strchr_normal);
  tcase_add_test(tc_core, test_s21_strchr_longStr);
  tcase_add_test(tc_core, test_s21_strchr_strNull);
  tcase_add_test(tc_core, test_s21_strchr_findCharEOF);
  tcase_add_test(tc_core, test_s21_strchr_strEOF);
  tcase_add_test(tc_core, test_s21_strchr_allEOF);
  tcase_add_test(tc_core, test_s21_strchr_embeddedNull);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_negative_char);
  tcase_add_test(tc_core, test_s21_strchr_last_char);
  tcase_add_test(tc_core, test_s21_strchr_multiple_occurrences);

  suite_add_tcase(s, tc_core);

  return s;
}