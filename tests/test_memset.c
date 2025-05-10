#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_memset_normal) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  char c = 'w';
  s21_size_t n = 2;

  ck_assert_str_eq(s21_memset(str1, c, n), memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_unicode) {
  char str1[] =
      "Венцель (Вацлав 4) — король Германии (формально Римский "
      "король) с 1376 года и король Чехии с 1378 года.";
  char str2[] =
      "Венцель (Вацлав 4) — король Германии (формально Римский "
      "король) с 1376 года и король Чехии с 1378 года.";
  char c = '!';
  s21_size_t n = 50;

  ck_assert_str_eq(s21_memset(str1, c, n), memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_empty_string) {
  char str1[1] = "";
  char str2[1] = "";
  char c = 'a';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(str1, c, n), memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_full_string) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  char c = 'x';
  s21_size_t n = sizeof(str1) - 1;

  ck_assert_str_eq(s21_memset(str1, c, n), memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_embedded_null) {
  char str1[] = {'H', 'e', '\0', 'l', 'o'};
  char str2[] = {'H', 'e', '\0', 'l', 'o'};
  char c = '!';
  s21_size_t n = 5;

  ck_assert_mem_eq(s21_memset(str1, c, n), memset(str2, c, n), n);
}
END_TEST

START_TEST(test_s21_memset_zero_n) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  char c = 'a';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(str1, c, n), memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_null_char) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  char c = '\0';
  s21_size_t n = 5;

  ck_assert_mem_eq(s21_memset(str1, c, n), memset(str2, c, n), n);
}
END_TEST

START_TEST(test_s21_memset_negative_char) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  char c = -1;
  s21_size_t n = 5;

  ck_assert_mem_eq(s21_memset(str1, c, n), memset(str2, c, n), n);
}
END_TEST

START_TEST(test_s21_memset_max_char) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  char c = 255;
  s21_size_t n = 5;

  ck_assert_mem_eq(s21_memset(str1, c, n), memset(str2, c, n), n);
}
END_TEST

START_TEST(test_s21_memset_str_null) {
  char *str1 = S21_NULL;
  char c = 23;
  s21_size_t n = 5;

  ck_assert_ptr_eq(s21_memset(str1, c, n), S21_NULL);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_normal);
  tcase_add_test(tc_core, test_s21_memset_unicode);
  tcase_add_test(tc_core, test_s21_memset_empty_string);
  tcase_add_test(tc_core, test_s21_memset_full_string);
  tcase_add_test(tc_core, test_s21_memset_embedded_null);
  tcase_add_test(tc_core, test_s21_memset_zero_n);
  tcase_add_test(tc_core, test_s21_memset_null_char);
  tcase_add_test(tc_core, test_s21_memset_negative_char);
  tcase_add_test(tc_core, test_s21_memset_max_char);
  tcase_add_test(tc_core, test_s21_memset_str_null);

  suite_add_tcase(s, tc_core);

  return s;
}