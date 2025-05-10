#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_memchr_normal) {
  char *str = "Hello world!";
  int findChar = 'w';
  int n = 12;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_unicode) {
  char *str =
      "Райан Гослинг — канадский киноактёр и музыкант.Родился 12 "
      "ноября 1980 года в Лондоне, Онтарио, Канада.";
  int findChar = '.';
  int n = 30;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_findChar_EFO) {
  char *str = "Hello world!";
  int findChar = '\0';
  int n = 12;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_str_EFO) {
  char *str = "\0";
  int findChar = 'w';
  int n = 1;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_str_empty) {
  char *str = "";
  int findChar = 'w';
  int n = 0;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_n_long) {
  char str[1200] = "Hello world!";
  int findChar = 'w';
  int n = 1200;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_n_short) {
  char *str = "Hello world!";
  int findChar = 'w';
  int n = 3;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_findChar_notFound) {
  char *str = "Hello world!";
  int findChar = 'x';
  int n = 12;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_str_long) {
  char str[100] =
      "This is a test string exactly 100 characters long, "
      "including spaces and punctuation";
  int findChar = 'x';
  int n = 12;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_findChar_aLot) {
  char str[100] = "xxxxxxxxxx";
  int findChar = 'x';
  int n = 12;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_embedded_null) {
  char str[100] = {'H', 'e', 'l', 'l', 'o', ',', '\0',
                   'W', 'o', 'r', 'l', 'd', '!'};
  int findChar = 'W';
  int n = 15;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_n_zero) {
  char *str = "Hello world!";
  int findChar = 'w';
  int n = 0;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), memchr(str, findChar, n));
}
END_TEST

START_TEST(test_s21_memchr_str_null) {
  char *str = S21_NULL;
  int findChar = 'w';
  int n = 0;
  ck_assert_ptr_eq(s21_memchr(str, findChar, n), S21_NULL);
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memchr_normal);
  tcase_add_test(tc_core, test_s21_memchr_unicode);
  tcase_add_test(tc_core, test_s21_memchr_findChar_EFO);
  tcase_add_test(tc_core, test_s21_memchr_str_EFO);
  tcase_add_test(tc_core, test_s21_memchr_str_empty);
  tcase_add_test(tc_core, test_s21_memchr_n_long);
  tcase_add_test(tc_core, test_s21_memchr_n_short);
  tcase_add_test(tc_core, test_s21_memchr_findChar_notFound);
  tcase_add_test(tc_core, test_s21_memchr_str_long);
  tcase_add_test(tc_core, test_s21_memchr_findChar_aLot);
  tcase_add_test(tc_core, test_s21_memchr_embedded_null);
  tcase_add_test(tc_core, test_s21_memchr_n_zero);
  tcase_add_test(tc_core, test_s21_memchr_str_null);

  suite_add_tcase(s, tc_core);
  return s;
}